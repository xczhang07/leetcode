class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> tmp;
        int sum = 0;
        dfs(ret, tmp, sum, k, n, 1);
        return ret;
    }
    
    void dfs(vector<vector<int>>& ret, vector<int>& tmp, int& sum, int k, int n, int idx)
    {
        if(sum > n)
            return;
        else if(tmp.size() > k)
            return;
        else if(sum == n)
        {
            if(tmp.size() == k)
            {
                ret.push_back(tmp);
                return;
            }
        }
        for(int i = idx; i <= 9; ++i)
        {
            sum += i;
            tmp.push_back(i);
            dfs(ret, tmp, sum, k, n, i+1);
            tmp.pop_back();
            sum -= i;
        }
        return;
    }
};

/*
Conclusion: a middle level algorithm issue, which is very similiar with combinations issue. 
Time Complexity: O(2^9)
Space Complexity: O(n)
*/
