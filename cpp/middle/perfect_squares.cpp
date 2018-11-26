class Solution {
public:
    int numSquares(int n) {
        if(n <= 0)
            return 0;
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= n; ++i)
        {
            for(int j = 1; i + j*j <= n; ++j)
                dp[i+j*j] = min(dp[i+j*j], dp[i]+1);
        }
        return dp[n];
    }
};


/*
state transfer function: dp[i+j*j] = min(dp[i+j*j], dp[i]+1)

Time Complexity is: O(n)
Space Complexity is: O(n)
*/
