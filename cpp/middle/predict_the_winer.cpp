/*
minmax strategy.
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        int l = 0;
        int r = nums.size()-1;
        dp = vector<int>(nums.size()*nums.size(), 0);
        return getScore(nums, l, r) >= 0;
    }
    
    int getScore(vector<int>& nums, int l, int r)
    {
        if(l == r)
            return nums[l];
        int idx = l*nums.size() + r;
        if(dp[idx] > 0)
            return dp[idx];
        
        dp[idx] = max(nums[l]-getScore(nums, l+1, r), nums[r]-getScore(nums, l, r-1));
        return dp[idx];
    }
    
    vector<int> dp;
};
