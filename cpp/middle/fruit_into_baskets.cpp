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


/*
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
