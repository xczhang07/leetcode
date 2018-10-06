class Solution {
public:
    string longestPalindrome(string s) {
        /* state transfer formula as following:
        j < i
        1. if i == j => dp[j][i] = 1
        2. if i - j < 2 && s[i] == s[j] => dp[j][i] = 1
        3. if s[i] == s[j] && dp[j+1][i-1] == 1 => dp[j][i] = 1
        */
        if(s.size() == 0)
            return "";
        int n = s.size();
        int dp[n][n] = {0};
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
               dp[i][j] = 0;
        }
        int len = 0;
        int left = 0;
        int right = 0;
        /* initialize the first state of the dp matrix */
        for(int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(i - j < 2 && (s[i] == s[j]))
                    dp[j][i] = 1;
                else if(i - j >= 2)
                {
                    if((s[i] == s[j]) && dp[j+1][i-1])
                        dp[j][i] = 1;
                }
                if(len < i-j+1 && dp[j][i])
                {
                    len = i-j+1;
                    left = j;
                    right = i;
                }
            }
        }
        return s.substr(left, right-left+1);
    }
};

/*
an middle level two dimision dynamic programming issue, need to think and re-practice it
*/
