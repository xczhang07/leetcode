class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool row_zero = false;
        bool col_zero = false;
        for(int i = 0; i < m; ++i)
        {
            if(matrix[i][0] == 0)
            {
                row_zero = true;
                break;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(matrix[0][i] == 0)
            {
                col_zero = true;
                break;
            }
        }
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(row_zero)
        {
            for(int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }
        if(col_zero)
        {
            for(int i = 0; i < n; ++i)
                matrix[0][i] = 0;
        }
        return;
    }
};

Conclusion:
Time Complexity: O(m*n)
Space Complexity: O(1)
