Solution#1 
Time Complexity is: O(n)
Space Complexity is: O(1)

class Solution {
public:
    bool isMatch(string s, string p) {
        int si = 0; /* index of s */
        int pi = 0; /* index of p */
        int star = -1; /* '*' position */
        int match = 0; /* the position match with "*" of p in s */
        while(si < s.size())
        {
            if(pi < p.size() && (s[si] == p[pi] || p[pi] == '?'))
            {
                ++si;
                ++pi;
            }
            else if(pi < p.size() && p[pi] == '*')
            {
                star = pi;
                ++pi;
                match = si;
            }
            else if(star != -1)
            {
                pi = star+1;
                match++;
                si = match;
            }
            else
                return false;
        }
        while(pi < p.size() && p[pi] == '*')
            ++pi;
        return pi == p.size();
    }
};

Solution 2: dynamic programming
Time Complexity is: O(m*n)
Space Complexity is: O(m*n)

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        /* initialization */
        dp[0][0] = true;
        for(int i = 1; i <= m; ++i)
        {
            if(p[i-1] == '*')
                dp[0][i] = dp[0][i-1];
        }
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};
