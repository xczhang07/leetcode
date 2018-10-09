class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
    
   
};

/*
Dynamic Programming solution.
Time Complexity is: O(n^2)
Space Complexity: O(n)
*/
