class Solution {
public:
    int minCut(string s) {
        if(s.size() <= 1)
            return 0;
        int n = s.size();
        vector<int> dp(n+1, 0);
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        /* dp[i] represents that the miniumum cuts to let string become palindrome from i to n */
        for(int i = 0; i <= n; ++i)
            dp[i] = n-i-1;
        
        for(int i = n-1; i >= 0; --i)
        {
            for(int j = i; j < n; ++j)
            {
                if(s[i] == s[j] && (j-i <= 2 || isPalin[i+1][j-1]))
                {
                    isPalin[i][j] = true;
                    dp[i] = min(dp[i], dp[j+1]+1);
                }
            }
        }
        return dp[0];
        
    }
};
