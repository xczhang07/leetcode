Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

Solution#1: BFS.
Time Complexity is: O(m*n)
Space Complexity is: O(m*n)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int islands = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    grid[i][j] = '0';
                    islands++;
                    while(!q.empty())
                    {
                        auto t = q.front();
                        q.pop();
                        for(auto dir : dirs)
                        {
                            int nx = t.first + dir.first;
                            int ny = t.second + dir.second;
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '0')
                                continue;
                            grid[nx][ny] = '0';
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
        return islands;
    }
};


Solution#2 DFS

Time Complexity is: O(m*n)
Space Complexity is: O(m*n)


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size();
        int ret = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++ret;
                    dfs(grid, i, j);
                }
            }
        }
        return ret;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(grid[i][j] == '0')
            return;
        vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0,1}, {0,-1}};
        int m = grid.size();
        int n  = grid[0].size();
        grid[i][j] = '0';
        
        for(auto dir : dirs)
        {
            int nx = i + dir.first;
            int ny = j + dir.second;
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '0')
                continue;
            dfs(grid, nx, ny);
        }
    }
};
