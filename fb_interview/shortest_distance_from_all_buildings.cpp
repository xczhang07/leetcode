You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
Example:

Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 7 

Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total 
             travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        int min_distance = INT_MAX;
        int room_val = 0;
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 1)
                {
                    min_distance = INT_MAX; /* key point ! */
                    vector<vector<int>> tmp = grid;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i, j));
                    while(!q.empty())
                    {
                        auto t = q.front();
                        q.pop();
                        for(auto d: dirs)
                        {
                            int nx = t.first + d.first;
                            int ny= t.second + d.second;
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != room_val)
                                continue;
                            grid[nx][ny] -= 1;
                            tmp[nx][ny] = tmp[t.first][t.second]+1;
                            dist[nx][ny] += (tmp[nx][ny]-1);
                            min_distance = min(min_distance, dist[nx][ny]);
                            q.push(make_pair(nx, ny));
                        }
                    }
                    --room_val;
                }
            }
        }
        
        if(min_distance == INT_MAX)
            return -1;
        else
            return min_distance;
    }
};
