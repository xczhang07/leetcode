class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        if(m == 0 || n == 0)
            return board;
        int row = click[0];
        int col = click[1];
        if(board[row][col] == 'M') /* if the input position is a M */
        {
            board[row][col] = 'X';
            return board;
        }
        else
        {
            /* check how many the "M" around the input position*/
            int cnt = 0;
            for(int i = -1; i < 2; ++i)
            {
                for(int j = -1; j < 2; ++j)
                {
                    int x = row+i;
                    int y = col+j;
                    if(x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    if(board[x][y] == 'M')
                        cnt++;
                }
            }
            if(cnt > 0)
                board[row][col] = cnt + '0';
            else
            {
                /* if no adjacent "M" found around input position, we deep the issue recursively */
                board[row][col] = 'B';
                for(int i = -1; i < 2; ++i)
                {
                    for(int j = -1; j < 2; ++j)
                    {
                        int x = row + i;
                        int y = col + j;
                        if(x < 0 || x >= m || y < 0 || y >= n)
                            continue;
                        if(board[x][y] == 'E')
                        {
                            vector<int> nextPos{x , y};
                            updateBoard(board, nextPos);
                        }
                    }
                }
            }
        }
        return board;
    }
};

/*
Time Complexity is : O(m*n)
Space Complexity is: O(m*n)
*/
