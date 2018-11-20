class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        for(int i = 0; i < matrix.size(); ++i)
        {
            vector<int> row_sum;
            int tmp_sum = 0;
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                tmp_sum += matrix[i][j];
                row_sum.push_back(tmp_sum);
            }
            sum.push_back(row_sum);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for(int i = row1; i <= row2; ++i)
        {
            if(col1 == 0)
                ret += sum[i][col2];
            else
                ret += (sum[i][col2]-sum[i][col1-1]);
        }
        return ret;
    }
    
private:
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
