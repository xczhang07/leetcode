class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) {
            return -1;
        }
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        set<pair<int,int>> visited;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                } else if(grid[i][j] == 1) {
                    fresh += 1;
                }
            }
        }
        if(fresh == 0) {
            return 0;
        }
        if(q.empty()) {
            return -1;
        }
        int rottenNum = 0;
        int min = 0;
        while(!q.empty()) {
            int k = q.size();
            while(k) {
                auto node = q.front();
                q.pop();
                for(auto d: dirs) {
                    int nx = node.first + d.first;
                    int ny = node.second + d.second;
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0) {
                        continue;
                    }
                    if(visited.count({nx, ny})) {
                        continue;
                    }
                    if(grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        rottenNum += 1;
                        visited.insert({nx, ny});
                        q.push({nx, ny});
                    }
                }
                k -= 1;
            }
            if(!q.empty()) {
                min += 1;
            }
        }
        if(rottenNum == fresh) {
            return min;
        } else {
            return -1;
        }
    }
};
