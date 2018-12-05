bfs
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int max_area = 0;
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    int area = 0;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    grid[i][j] = 0;
                    while(!q.empty())
                    {
                        auto f = q.front();
                        q.pop();
                        area++;
                        for(auto dir : dirs)
                        {
                            int x = f.first + dir.first;
                            int y = f.second + dir.second;
                            if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
                                continue;
                            if(grid[x][y] == 1)
                            {
                                q.push(make_pair(x, y));
                                grid[x][y] = 0;
                            }
                        }
                    }
                    max_area = max(max_area, area);
                }
                
            }
        }
        return max_area;
    }
    
};


dfs

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int max_area = INT_MIN;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                int sum = 0;
                if(grid[i][j] == 1)
                    dfs(grid, i, j, sum);
                max_area = max(max_area, sum);
            }
        }
        return max_area;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& area)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if(grid[i][j] == 1)
        {
            ++area;
            grid[i][j] = 0;
            dfs(grid, i-1, j, area);
            dfs(grid, i+1, j, area);
            dfs(grid, i, j-1, area);
            dfs(grid, i, j+1, area);
        }
        else
            return;
    }
};
