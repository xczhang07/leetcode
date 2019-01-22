Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.


Time Complexity: constructor O(m*n), getRangeSum: O(1)

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 1; i < m; ++i)
            nums[i][0] += nums[i-1][0];
        for(int j = 1; j < n; ++j)
            nums[0][j] += nums[0][j-1];
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
                nums[i][j] += nums[i-1][j] + nums[i][j-1]-nums[i-1][j-1];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = helper(row2, col2)-helper(row2, col1-1)-helper(row1-1, col2) + helper(row1-1, col1-1);
        return sum;
    }
    
    int helper(int i, int j)
    {
        if(i >= 0 && j >= 0)
            return nums[i][j];
        else
            return 0;
    }
    private:
    
    vector<vector<int>> nums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
