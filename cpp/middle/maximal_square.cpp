class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /*
        Time Complexity is: O(m*n)
        Space Complexity is: O(m*n)
        */
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int len = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i == 0 || j == 0 || matrix[i][j] == '0')
                    dp[i][j] = matrix[i][j]-'0';
                else
                {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
                }
                len = max(len, dp[i][j]);
            }
        }
        return len*len;
    }
};
