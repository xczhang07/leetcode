class Solution {
public:
    /*
    this issue let us implement a program to reserve only the grid which was surrounded by 'X'.
    our solution as following:
    according to the first row, last row, first column, and last column(which touch the border of the matrix),
    if an element on the border is marked with 'O', we can know all the element which mark "O" adjacent to this grid 
    should be changed to 'X', we use dfs to change the label of those grid from 'O' to 'M'. after caculating all the four 
    edges, we do one more travesal for the matrix, mark all the 'M' grid to 'O', marked all the 'O' to 'X', surrounded element
    should be change to 'X'
    Time Complexity: O(mn)
    Space Complexity: O(mn)
    */
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        if(i >= board.size() || j >= board[0].size())
            return;
        if(board[i][j] == 'O')
        {
            board[i][j] = 'M';
            dfs(board, i+1, j);
            dfs(board, i-1, j);
            dfs(board, i, j+1);
            dfs(board, i, j-1);
        }
        return;
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        int n = board.size();
        int m = board[0].size();
        if(m == 0) return;
        for(int i = 0; i < n; ++i)
        {
            if(board[i][0] == 'O')
                dfs(board, i, 0);
        }
        for(int i = 0; i < n; ++i)
        {
            if(board[i][m-1] == 'O')
                dfs(board, i, m-1);
        }
        for(int i = 0; i < m; ++i)
        {
            if(board[0][i] == 'O')
                dfs(board, 0, i);
        }
        for(int i = 0; i < m; ++i)
        {
            if(board[n-1][i] == 'O')
                dfs(board,n-1, i);
        }
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'M')
                    board[i][j] = 'O';
            }
        }
        return;
    }
    
    
};

Conclusion:
Time Complexity: O(mn)
Space Complexity: O(mn)

graph dfs travel


// BFS version
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) {
            return;
        }
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        queue<pair<int,int>> q;
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 || j == 0 || i == m-1 || j == n-1) {
                    if(board[i][j] == 'O') {
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
        }
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            for(auto d: dirs) {
                int nx = x + d.first;
                int ny = y + d.second;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
                    continue;
                }
                if(board[nx][ny] == 'O') {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        for(int i = 1; i < m-1; ++i) {
            for(int j = 1; j < n-1; ++j) {
                if(board[i][j] == 'O' and visited[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
