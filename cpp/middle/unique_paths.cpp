class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0)
            return 0;
        vector<vector<int>> matrix(m, vector<int>(n,0));
        for(int i = 0; i < m; ++i)
            matrix[i][0] = 1;
        for(int i = 0; i < n; ++i)
            matrix[0][i] = 1;
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
        }
        return matrix[m-1][n-1];
    }
};


Conclusion:
dynamic programming， 动态规划，先对第一横行和第一竖行initialize，全部初始化为1. 因为机器人只可以往下和右边移动，
所以动态规划表达式为：matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];

Time Complexity: O(m*n)
Space Complexity: O(m*n)
