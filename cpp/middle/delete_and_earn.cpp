class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(10001, 0);
        for(auto num : nums)
            dp[num] += num;
        for(int i = 2; i < 10001; ++i)
            dp[i] = max(dp[i-1], dp[i-2]+dp[i]);
        return dp[10000];
    }
};
