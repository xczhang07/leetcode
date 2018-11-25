leetcode 上有一道题，fruit in baskets.
https://leetcode.com/problems/fruit-into-baskets/description/

这道题其实就是让求给定一个数组，在数组中求出包含两个元素的最长子数组的问题。解法如下：
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if(tree.size() < 2)
            return tree.size();
        int ret = 0;
        int num = 0;
        unordered_map<int,int> m;
        int n = tree.size();
        int start = 0;
        for(int i = 0; i < n; ++i)
        {
            m[tree[i]]++;
            num++;
            if(m.size() <= 2)
                ret = max(ret, num);
            if(m.size() > 2)
            {
                while(start < i && m.size() > 2)
                {
                    --m[tree[start]];
                    --num;
                    if(m[tree[start]] == 0)
                        m.erase(tree[start]);
                    ++start;
                }
            }
        }
        return ret;
    }
};

咱们来具体分析一下解题思路与步骤：
1. 首先判断一下输入的数组是否合法，如果不合法的话，那就没有戏可以唱了。
2. 其次，咱们来建立一个哈希表。
3. 在建立一个变量num，来记录数组中出现两个字符时候的长度。
4. 从头开始遍历数组，遇见一个元素，我们就往哈希表中插入这个元素，并且记录这个元素出现的次数，与此同时，num自增1
(因为是顺序便利的，所以可以保证是子数组)
5. 插入完一个元素之后，我们来检测一下哈希表的长度，如果是2的话，我们更新一下最长长度。
6. 如果哈希表的长度大于2的话，我们从左向右移动window，如果当一个元素出现的次数为0的时候，我们从哈希表将这个元素移除。
7. 遍历完一遍之后，便可得到最长含有两个元素的子数组。

通过这道题，我们可以把这个题目延伸一下，如果让计算一个数组中含有k个元素的最长子数组问题，我们可以用下面代码进行测算:
class Solution {
public:
    int totalFruit(vector<int>& tree, int k) {
        if(tree.size() < k)
            return tree.size();
        int ret = 0;
        int num = 0;
        unordered_map<int,int> m;
        int n = tree.size();
        int start = 0;
        for(int i = 0; i < n; ++i)
        {
            m[tree[i]]++;
            num++;
            if(m.size() <= k)
                ret = max(ret, num);
            if(m.size() > k)
            {
                while(start < i && m.size() > k)
                {
                    --m[tree[start]];
                    --num;
                    if(m[tree[start]] == 0)
                        m.erase(tree[start]);
                    ++start;
                }
            }
        }
        return ret;
    }
};


相似的题目还有:
https://leetcode.com/problems/minimum-window-substring/description/
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/
https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/
https://leetcode.com/problems/minimum-size-subarray-sum/description/
https://leetcode.com/problems/minimum-window-substring/description/

