class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        matrix[0][0] = grid[0][0];
        for(int i = 1; i < m; ++i)
            matrix[i][0] = matrix[i-1][0] + grid[i][0];
        for(int i = 1; i < n; ++i)
            matrix[0][i] = matrix[0][i-1] + grid[0][i];
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
                matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1]) + grid[i][j];
        }
        return matrix[m-1][n-1];
    }
};


Conclustion:
二维动态规划，状态转移方程为: matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1]) + grid[i][j]; i和j 都是从1 开始计算的。

Time Complexity: O(m*n)
Space Complexity: O(m*n)
