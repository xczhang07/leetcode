class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        vector<int> colUpCnt(n,0);
        vector<int> colDownCnt(n,0);
        int ret = 0;
        for(int i = 0; i < m; ++i)
        {
            int rowLeftCnt = 0;
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 'E')
                {
                    rowLeftCnt++;
                    colUpCnt[j]++;
                }
                else if(grid[i][j] == '0')
                    dp[i][j] += (rowLeftCnt+colUpCnt[j]);
                else if(grid[i][j] == 'W')
                {
                    rowLeftCnt = 0;
                    colUpCnt[j] = 0;
                }
            }
        }
        
        for(int i = m-1; i >= 0; --i)
        {
            int rowRightCnt = 0;
            for(int j = n-1; j >= 0; --j)
            {
                if(grid[i][j] == 'E')
                {
                    rowRightCnt++;
                    colDownCnt[j]++;
                }
                else if(grid[i][j] == '0')
                {
                    dp[i][j] += (rowRightCnt+colDownCnt[j]);
                    ret = max(ret, dp[i][j]);
                }
                else if(grid[i][j] == 'W')
                {
                    rowRightCnt = 0;
                    colDownCnt[j] = 0;
                }
            }
        }
        return ret;
    }
};

/*
Time Complexity is: O(m*n)
Space Complexity is: O(m*n)
*/
