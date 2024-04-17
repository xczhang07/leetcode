这是这个帖子的第一题 https://www.1point3acres.com/bbs/thread-1061734-1-1.html

struct Point {
    int x;
    int y;
    vector<pair<int, int>> path;
    Point(int a, int b, vector<pair<int,int>> vec) {
        x = a;
        y = b;
        path = vec;
    }
};

void shortestPathWithObstacles(vector<vector<int>>& grid, vector<pair<int,int>>& paths) {
    if(grid.size() == 0 || grid[0].size() == 0) {
        return;
    }
    int m = grid.size(), n = grid[0].size();
    if(grid[0][0] == 1 || grid[m-1][n-1] == 1) {
        return;
    }
    queue<Point> q;
    Point startPoint(0, 0, {{0,0}});
    grid[0][0] = 2;
    q.push(startPoint);
    vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    while(!q.empty()) {
        auto node = q.front();
        q.pop();
        if(node.x == m-1 && node.y == n-1) {
            paths = node.path;
            return;
        }
        for(auto& dir: dirs) {
            int nx = node.x + dir.first;
            int ny = node.y + dir.second;
            if(nx < 0 || nx > m-1 || ny < 0 || ny > n-1 || grid[nx][ny] == 1 || grid[nx][ny] == 2) {
                continue;
            }
            Point nextPoint(nx, ny, node.path);
            nextPoint.path.push_back({nx, ny});
            q.push(nextPoint);
            grid[nx][ny] = 2; // mark as visited.
        }
    }
    return;
}
