class Solution {
public:
    bool isMatch(string s, string p) {
        /* if either one of the input string is empty, the result is false */
        if(p.empty())
            return s.empty();
        int s_len = s.size();
        int p_len = p.size();
        vector<vector<bool>> dp(p_len+1, vector<bool>(s_len+1, false));
        dp[0][0] = true;
        for(int j = 0; j < p.size(); ++j)
        {
            if(p[j] == '*')
                dp[j+1][0] = dp[j-1][0];
        }
        for(int i = 1; i <= p_len; ++i)
        {
            for(int j = 1; j <= s_len; ++j)
            {
                if(p[i-1] == s[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*')
                {
                    if(p[i-2] != s[j-1] && p[i-2] != '.')
                        dp[i][j] = dp[i-2][j];
                    else /* the case for p[i-2] == s[j-1] */
                        dp[i][j] = dp[i-1][j] || dp[i-2][j] || dp[i][j-1];
                }
            }
        }
        return dp[p_len][s_len];
    }
};

Conclusion:
a very hard issue on leetcode, dynamic programming, translate function as following:
d[i][j] represents whether or not p[0,i] matches s[0,j] 
if p[i-1] == s[j-1] => dp[i][j] = dp[i-1][j-1]
if p[i-1] == "." => dp[i][j] = dp[i-1][j-1]
if p[i-1] == "*" :
	if p[i-2] != s[j-1] && p[i-2] != "." => dp[i][j] = dp[i-2][j]
        if p[i-2] == s[j-1] => dp[i][j] = dp[i-1][j] || dp[i-2][j] || dp[i][j-1] 

	case example:
		dp[i][j] = dp[i-1][j] => s = "abc", p = "abc*"
		dp[i][j] = dp[i-2][j] => s = "ab", p = "ab.*"
		dp[i][j] = dp[i][j-1] => s = "abcccccc", p = "abc*"

Time Complexity: O(m*n)
Space Complexity: O(m*n) 
