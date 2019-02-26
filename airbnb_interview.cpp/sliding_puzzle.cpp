On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
Input: board = [[3,2,4],[1,5,0]]
Output: 14
Note:

board will be a 2 x 3 array as described above.
board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return 0;
        int steps = 0;
        set<vector<vector<int>>> visited;
        queue<pair<vector<vector<int>>, pair<int,int>>> q;
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,-1}, {0,1}};
        vector<vector<int>> correct = {{1,2,3}, {4,5,0}};
        
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[i].size(); ++j)
            {
                if(board[i][j] == 0)
                    q.push(make_pair(board, make_pair(i,j)));
            }
        }
        visited.insert(board);
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; ++i)
            {
                auto top = q.front();
                q.pop();
                if(top.first == correct)
                    return steps;
                auto zero = top.second;
                for(auto dir: dirs)
                {
                    int x = zero.first + dir.first;
                    int y = zero.second + dir.second;
                    if(x < 0 || x >= 2 || y < 0 || y >= 3)
                        continue;
                    auto next = top.first;
                    swap(next[zero.first][zero.second], next[x][y]);
                    if(visited.count(next))
                        continue;
                    visited.insert(next);
                    q.push(make_pair(next, make_pair(x,y)));
                }
            }
            ++steps;
        }
        
        return -1;
    }
};
