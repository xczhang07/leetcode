class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int raw_num = matrix.size();
        int col_num = matrix[0].size();
        for(int i = 0; i < raw_num; ++i)
        {
            for(int j = 0; j < col_num; ++j)
            {
                if((i+1) < raw_num && (j+1) < col_num)
                {
                    if(matrix[i][j] != matrix[i+1][j+1])
                        return false;
                }
            }
        }
        return true;
    }
};

Conclusion:
easy algorithm issue, iterate the matrix starts from element matrix[0][0] is ok!

Time Complexity: O(m*n)
Space Complexity: O(1)

