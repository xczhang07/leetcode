class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0 || rooms[0].size() == 0)
            return;
        int m = rooms.size();
        int n = rooms[0].size();
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int empty = INT_MAX;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(rooms[i][j] == empty)
                {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    visited[i][j] = true;
                    int steps = 0;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    bool find = false;
                    while(!q.empty())
                    {
                        int s = q.size();
                        for(int k = 0; k < s; ++k)
                        {
                            auto t = q.front();
                            q.pop();
                            if(rooms[t.first][t.second] == 0)
                            {
                                find=true;
                                break;
                            }
                            for(auto dir : dirs)
                            {
                                int x = t.first + dir.first;
                                int y = t.second + dir.second;
                                if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || rooms[x][y] == -1)
                                    continue;
                                visited[x][y] = true;
                                q.push(make_pair(x, y));
                            }
                        }
                        if(find)
                            break;
                        steps++;
                    }
                    if(find)
                        rooms[i][j] = steps;
                }
            }
        }
    }
};

// An simple solution as below
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0) {
            return;
        }
        int m = rooms.size();
        int n = rooms[0].size();
        int gate = 0;
        int wall = -1;
        int empty = INT_MAX;
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int, int>> q;
        // find all gates and push into the queue
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(rooms[i][j] == gate) {
                    q.push({i, j});
                }
            }
        }
        int distance = 0;
        // bfs to fill up the shortest distance for each empty room to gate.
        while(!q.empty()) {
            int k = q.size();
            while(k) {
                auto node = q.front();
                q.pop();
                for(auto d: dirs) {
                    int x = node.first + d.first;
                    int y = node.second + d.second;
                    if(x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    if(rooms[x][y] == wall) {
                        continue;
                    }
                    if(rooms[x][y] > distance+1) {
                        rooms[x][y] = distance+1;
                        q.push({x, y});
                    }
                }
                k -= 1;
            }
            distance += 1;
        }
        return;
    }
};
