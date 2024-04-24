class Solution {
public:
    // mark the 1st island to another number which is used to distinguish the island2;
    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int& row, int& col) {
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            for(auto& d: dirs) {
                int nx = top.first + d.first;
                int ny = top.second + d.second;
                if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
        }
    }

    // for every node in island2 find the shortest distance to island1
    int bfs2(vector<vector<int>>& grid, queue<vector<int>>& q, int& row, int& col, set<pair<int, int>>& visited) {
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int ret = INT_MAX;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            for(auto& d: dirs) {
                int nx = node[0] + d.first;
                int ny = node[1] + d.second;
                if(nx >= 0 && nx < row && ny >= 0 && ny < col && !visited.count({nx,ny})) {
                    if(grid[nx][ny] == 2) {
                        ret = min(ret, node[2]);
                    } else {
                        q.push({nx, ny, node[2]+1});
                        visited.insert({nx,ny});
                    }
                }
            }
        }
        return ret;
    }

    // Two BFS solution.
    int shortestBridge(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        queue<pair<int,int>> q1;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 2;
                    q1.push({i, j});
                    goto jump;
                }
            }
        }
        jump:
            bfs(grid, q1, m, n);
            // find the start point of island2
            set<pair<int,int>> visited;
            queue<vector<int>> q2;
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(grid[i][j] == 1) {
                        q2.push({i, j, 0});
                        visited.insert({i,j});
                    }
                }
            }
            return bfs2(grid, q2, m, n, visited);
    }
};
