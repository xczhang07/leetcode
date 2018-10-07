class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> current;
        vector<vector<int>> ret;
        if(n == 1)
            return {};
        dfs(current, ret, n, 2);
        return ret;
    }
    
    void dfs(vector<int>& current, vector<vector<int>>& ret, int n, int start)
    {
        if(current.size() >= 1)
        {
            current.push_back(n);
            ret.push_back(current);
            current.pop_back();
        }
        for(int i = start; i*i <= n; ++i)
        {
            if(n%i == 0)
            {
                current.push_back(i);
                dfs(current, ret, n/i, i);
                current.pop_back();
            }
        }
    }
};


/*
Conclusion:
back-tracking issue for leetcode, a middle level, same as combination, permutation issue...
*/
