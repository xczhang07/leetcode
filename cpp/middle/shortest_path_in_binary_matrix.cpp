class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) {
            return {};
        }
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}, {-1,-1}, {1,1}, {1,-1}, {-1,1}};
        queue<pair<pair<int, int>, int>> q;
        q.push({{0,0}, 1});
        grid[0][0] = 1;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            if(node.first.first == n-1 && node.first.second == n-1) {
                return node.second;
            }
            for(auto dir : dirs) {
                int nx = node.first.first + dir.first;
                int ny = node.first.second + dir.second;
                if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1 || grid[nx][ny] == 1) {
                    continue;
                }
                q.push({{nx,ny}, node.second+1});
                grid[nx][ny] = 1;
            }
        }
        return -1;
    }
};
