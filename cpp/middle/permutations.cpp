class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> tmp;
        vector<vector<int>> ret;
        dfs(nums, visited, ret, tmp);
        return ret;
    }
    
    void dfs(vector<int>& nums, vector<bool>& visited, vector<vector<int>>& ret, vector<int>& tmp)
    {
        if(tmp.size() == nums.size())
        {
            ret.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(!visited[i])
            {
                tmp.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, visited, ret, tmp);
                visited[i] = false;
                tmp.pop_back();
            }
        }
        return;
    }
};

/*
Conclusion: middle level algorithm issue, backtracking issue
*/
