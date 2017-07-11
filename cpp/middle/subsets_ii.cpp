class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        ret.push_back(tmp);
        if(nums.size() == 0)
            return ret;
        sort(nums.begin(), nums.end()); // inorder to skip the duplicate answer, we need to sort the input array
        int idx = 0;
        dfs(ret, tmp, nums, idx);
        return ret;
    }
    
    void dfs(vector<vector<int>>& ret, vector<int>& tmp, vector<int>& nums, int idx)
    {
        if(idx >= nums.size())
            return;
        for(int i = idx; i < nums.size(); ++i)
        {
            tmp.push_back(nums[i]);
            ret.push_back(tmp);
            dfs(ret, tmp, nums, i+1);
            tmp.pop_back();
            while(i < nums.size()-1 && nums[i] == nums[i+1])
                ++i;
        }
    }
};

Conclusion:

Middle level algorithm issue, the time complexity is the same with subsets, which is: O(n*2^n), space complexity is: O(n)

