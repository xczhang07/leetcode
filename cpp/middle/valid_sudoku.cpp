class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        if(r == 0 || c == 0)
            return false;
        vector<vector<int>> row(r, vector<int>(c, 0));
        vector<vector<int>> col(c, vector<int>(r, 0));
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        
        /* iterate the two dimision input board matrix */
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                char e = board[i][j];
                if(e >= '1' && e <= '9')
                {
                    int n = e-'0'-1;
                    if(row[i][n] == 1 || col[j][n] == 1 || matrix[3*(i/3)+j/3][n] == 1) /* 3*3 matrix index caculate is: 3*(i/3)+j/3 */
                        return false;
                    row[i][n] = 1;
                    col[j][n] = 1;
                    matrix[3*(i/3)+j/3][n] = 1;
                }
            }
        }
        return true;
    }
    
};


/*
a middle level algorithm issue.
Time Complexity is: O(n^2)
Space Complexity is: O(n^2)
*/
