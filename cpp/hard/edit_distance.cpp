class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0)
            return word2.size();
        else if(word2.size() == 0)
            return word1.size();
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0)); /* initialize dynamic programming two dimision array */
        /* pre process, if word2 is empty */
        for(int i = 0; i <= m; ++i)
            dp[i][0] = i;
        /* pre process, if word1 is empty */
        for(int j = 0; j <= n; ++j)
            dp[0][j] = j;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
        return dp[m][n];
    }
};

Conclusion:
a hard level algorithm issue, dynamice programming.
state transfer function as following:
if word1[i-1] == word2[j-1] => dp[i][j] = dp[i-1][j-1]
else 
   dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1

dp[i-1][j]+1 // delete one charactor from word1
dp[i][j-1]+1 // add one charactor into word1
dp[i-1][j-1]+1 // replace one charactor in word1

Time Complexity: O(m*n)
Space Complexity: O(m*n)
