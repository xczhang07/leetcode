class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i)
        {
            if(obstacleGrid[i][0] == 0)
                matrix[i][0] = 1;
            else
                break;
        }
        for(int i = 0; i < n; ++i)
        {
            if(obstacleGrid[0][i] == 0)
                matrix[0][i] = 1;
            else
                break;
        }
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(obstacleGrid[i][j] == 1)
                    matrix[i][j] = 0;
                else
                    matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        }
        return matrix[m-1][n-1];
    }
};


Conclusion:
dynamic programming.
一道动态规划问题，和unique paths很相像，就是有了obstacle，所以状态转移方程会有变化。
obstacleGrid[i][j] == 0: matrix[i][j] = matrix[i-1][j] + matrix[i][j-1] ／／ 没有阻挡的情况下
obstacleGrid[i][j] == 1: matrix[i][j] = 0 ／／有了阻挡的情况下
Time Complexity: O(m*n)
Space Complexity: O(m*n)
