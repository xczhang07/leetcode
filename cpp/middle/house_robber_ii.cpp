class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        else if(nums.size() == 2)
            return max(nums[0], nums[1]);
        return max(rob_part(nums, 0, nums.size()-1), rob_part(nums, 1, nums.size()));
    }
    
    int rob_part(vector<int>& nums, int left, int right)
    {
        if(right - left <= 1)
            return max(nums[left], nums[right]);
        vector<int> dp(right-left+1, 0);
        dp[left] = nums[left];
        dp[left+1] = max(nums[left], nums[left+1]);
        for(int i = left+2; i < right; ++i)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[right-1];
        
    }
};

