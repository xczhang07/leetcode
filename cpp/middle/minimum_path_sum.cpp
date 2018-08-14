class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 0 || m == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        /* initialize the dynamic grid raw and colmun */
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; ++i)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j = 1; j < m; ++j)
            dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i = 1; i < n; ++i)
        {
            for(int j = 1; j < m; ++j)
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
        return dp[n-1][m-1];
            
    }
};


Conclusion: middle level issue on leetcode, dynamic programming, we can maintain a matrix to caculate the dynamic matrix.
Time Complexity: O(mn)
Space Complexity: O(mn)
