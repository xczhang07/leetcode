/*
Time Complexity is: O(m*n*k)
Space Complexity is: O(m*n)

algorithm: BFS
*/

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        if(m == 0 || n == 0)
            return 0;
        int res = INT_MAX;
        int val = 0;
        vector<vector<int>> sum(m, vector<int>(n, 0));
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    res = INT_MAX;
                    vector<vector<int>> dist = grid;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    while(!q.empty())
                    {
                        auto top = q.front();
                        int x = top.first, y = top.second;
                        q.pop();
                        for(auto dir : dirs)
                        {
                            int nx = x + dir.first;
                            int ny = y + dir.second;
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != val)
                                continue;
                            --grid[nx][ny];
                            dist[nx][ny] = dist[x][y]+1;
                            sum[nx][ny] += dist[nx][ny]-1;
                            q.push(make_pair(nx, ny));
                            res = min(res, sum[nx][ny]);
                        }
                    }
                    --val;
                }
            }
        }
        
        if(res == INT_MAX)
            return -1;
        else
            return res;
    }
};
