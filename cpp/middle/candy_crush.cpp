This question is about implementing a basic elimination algorithm for Candy Crush.

Given a 2D integer array board representing the grid of candy, different positive integers board[i][j] 
represent different types of candies. A value of board[i][j] = 0 represents that the cell at position (i, j) is empty. 
The given board represents the state of the game following the player's move. 
Now, you need to restore the board to a stable state by crushing candies according to the following rules:

If three or more candies of the same type are adjacent vertically or horizontally, "crush" them all at the same time - 
these positions become empty.
After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, 
then these candies will drop until they hit a candy or bottom at the same time. (No new candies will drop outside the top boundary.)
After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
If there does not exist more candies that can be crushed (ie. the board is stable), then return the current board.
You need to perform the above rules until the board becomes stable, then return the current board.


The length of board will be in the range [3, 50].
The length of board[i] will be in the range [3, 50].
Each board[i][j] will initially start as an integer in the range [1, 2000].


class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        while(true)
        {
            vector<pair<int,int>> crush;
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if(board[i][j] == 0)
                        continue;
                    int x0 = i, x1 = i, y0 = j, y1 = j;
                    while(x0 >= 0 && x0 > i-3 && board[i][j] == board[x0][j])
                        --x0;
                    while(x1 < m && x1 < i+3 && board[i][j] == board[x1][j])
                        ++x1;
                    while(y0 >= 0 && y0 > j-3 && board[i][j] == board[i][y0])
                        --y0;
                    while(y1 < n && y1 < j+3 && board[i][j] == board[i][y1])
                        ++y1;
                    if(x1-x0 > 3 || y1-y0 > 3)
                        crush.push_back(make_pair(i,j));
                }
            }
            
            if(crush.empty())
                break;
            
            for(auto c: crush)
                board[c.first][c.second] = 0;
            /* perform the drop process */
            for(int j = 0; j < n; ++j)
            {
                int s = m-1;
                for(int i = m-1; i >= 0; --i)
                {
                    if(board[i][j] != 0)
                    {
                        swap(board[i][j], board[s][j]);
                        --s;
                    }
                }
            }
            
        }
        
        return board;
    }
};
