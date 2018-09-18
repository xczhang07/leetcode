class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> tmp;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
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
            dfs(ret, candidates, tmp, target, sum, i+1);
            tmp.pop_back();
            sum -= candidates[i];
            while(i+1 < candidates.size() && candidates[i] == candidates[i+1])
                ++i;
        }
        return;
    }
};


/*
Conclusion:
an middle level algorithm issue on leetcode, not too diffcult, backtracking + dfs can resolve the issue.
Time Complexity: O(k*2^n)
Space Complexity: O(n)
time complexity please refer to link: 
https://leetcode.com/problems/combination-sum/discuss/16634/if-asked-to-discuss-the-time-complexity-of-your-solution-what-would-you-say

*/
