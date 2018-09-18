class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> tmp;
        int sum = 0;
        dfs(ret, candidates, tmp, target, sum, 0);
        return ret;
    }
    
    void dfs(vector<vector<int>>& ret, vector<int>& candidates, vector<int>& tmp, int& target, int& sum, int idx)
    {
        if(sum > target)
            return;
        else if(sum == target)
        {
            ret.push_back(tmp);
            return;
        }
        for(int i = idx; i < candidates.size(); ++i)
        {
            sum += candidates[i];
            tmp.push_back(candidates[i]);
            dfs(ret, candidates, tmp, target, sum, i);
            tmp.pop_back();
            sum -= candidates[i];
        }
        return;
    }
};

/*
Conclusion:
a middle level algorithm issue.backtracking + dfs
Time Complexity: O(k*2^n)
Space Complexity: O(n)
*/
