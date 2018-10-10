class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i)
            dp[i][i] = 1;
        
        /* cl is length of substring */
        for(int cl = 2; cl <= n; ++cl)
        {
            for(int i = 0; i < n-cl+1; ++i)
            {
                int j = i+cl-1;
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};

/*
Conclusion:
a middle level algorithm issue, dynamic programming, state transfer function as following:
if s[i] == s[j]: dp[i][j] = dp[i+1][j-1] + 2
else: dp[i][j] = max(dp[i+1][j], dp[i][j-1])
Time Complexity is: O(n^2)
Space Complexity is: O(n^2)
*/


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /*
        state transfer function as following:
        if s[i] == s[j] => dp[j][i] = dp[j+1][i-1] + 2;
        else dp[j][i] = max(dp[j+1][i], dp[j][i-1])
        
        */
        if(s.size() == 0)
            return 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
            for(int j = i-1; j >= 0; --j)
            {
                if(s[i] == s[j])
                    dp[j][i] = dp[j+1][i-1]+2;
                else
                    dp[j][i] = max(dp[j+1][i], dp[j][i-1]);
            }
        }
        return dp[0][n-1];
    }
};
