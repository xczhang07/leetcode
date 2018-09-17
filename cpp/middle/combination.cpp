class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> tmp;
        dfs(ret, tmp, k, n, 1);
        return ret;
    }
    
    
    void dfs(vector<vector<int>>& ret, vector<int>& temp, int k, int n, int idx)
    {
        if(temp.size() == k)
        {
            ret.push_back(temp);
            return;
        }
        for(int i = idx; i <= n; ++i)
        { 
            temp.push_back(i);
            dfs(ret, temp, k, n, i+1);
            temp.pop_back();   
        }
        return;
    }
};


/*
Conclusion: a middle level algorithm issue, we can use backtracking and dfs to resolve it
Time Complexity: O(2^n*k)
Space Complexity: O(n)
*/
