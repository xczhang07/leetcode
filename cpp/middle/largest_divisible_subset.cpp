class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        /* https://www.youtube.com/watch?v=kzUw5YcTvLo */
        vector<int> ret;
        if(nums.size() == 0)
            return ret;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 0);
        vector<int> sol(n, -1);
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[i]%nums[j] == 0 && dp[i] < dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    sol[i] = j;
                }
            }
            if(dp[i] > dp[ans])
                ans = i;
        }
        
        for(int i = ans; i != -1; i = sol[i])
            ret.push_back(nums[i]);
        return ret;
    }
};
