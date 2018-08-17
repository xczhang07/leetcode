class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> map;
        int count = 0;
        int ret = 0;
        for(auto t : tasks)
            count = max(count, ++map[t]);
        ret = (count-1)*(n+1);
        for(auto e : map)
        {
            if(e.second == count)
                ++ret;
        }
        int size = tasks.size();
        return max(size,ret);
    }
};

Conclusion: a middle level algorithm issue on leetcode, we can caculate the most frequence task's number m, 
then we can divide the total into group number: m-1, in each group we can schedule (n+1) tasks. 
so the answer is: (m-1)*(n+1)+p, p is the number of the tasks which has the same frequence with the most one, 
for example: AAABBBCC 2 => ABCABCAB, ans = (3-1)*(2+1) + 2, because both A and B has the most frequence 3 in this case.
for another example: AAAABBBEEFFGGM 3 => ABEFABEGABFGAM, in this case, the ans is: (4-1)*(3+1)+1 = 12, however, it is incorrect
, because we don't use idle in this case, so the answer should be: sizeof(input string): 14.
So the final solustion should be: max(tasks.size(), (k-1)*(n+1)+p);

Time Complexity: O(n)
Space Complexity: O(n)
