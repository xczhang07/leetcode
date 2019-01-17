class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ret;
        set<vector<int>> s;
        if(nums.size() == 0) return ret;
        int idx = 0;
        vector<int> sol;
        dfs(s, sol, nums, idx);
        for(auto e : s)
            ret.push_back(e);
        return ret;
    }
    
    void dfs(set<vector<int>>& s, vector<int>& sol, vector<int>& nums, int idx)
    {
        if(sol.size() > 1)
        {
            s.insert(sol);
        }
        for(int i = idx; i < nums.size(); ++i)
        {
            if(sol.size() == 0 || sol.back() <= nums[i])
            {
                sol.push_back(nums[i]);
                dfs(s, sol, nums, i+1);
                sol.pop_back();
            }
        }
        return;
    }
};

Time Complexity is: O(2^n)
Space Complexity is: O(n)
