According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?


Time Complexity is: O(m*n)
Space Complexity is: O(1)

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return;
        int m = board.size();
        int n = board[0].size();
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}, {1,-1}, {-1,1}, {1,1}, {-1,-1}};
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int count = 0;
                for(auto d : dirs)
                {
                    int x = d.first + i;
                    int y = d.second + j;
                    if(x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    if(board[x][y]&1 == 1)
                        count++;
                }
                if(board[i][j] == 0)
                {
                    if(count == 3)
                        board[i][j] = 2;
                }
                else
                {
                    if(count < 2)
                        board[i][j] = 1;
                    else if(count == 2 || count == 3)
                        board[i][j] = 3;
                    else if(count > 3)
                        board[i][j] = 1;
                }
            }
        }
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                board[i][j] >>= 1;
            }
        }
        return;
    }
};
