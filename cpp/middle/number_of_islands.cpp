class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++islands;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
    
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        if(r < 0 || r > grid.size()-1)
            return;
        else if(c < 0 || c > grid[0].size()-1)
            return;
        if(grid[r][c] == '1')
        {
            grid[r][c] = '3';
            dfs(grid, r-1, c);
            dfs(grid, r+1, c);
            dfs(grid, r, c-1);
            dfs(grid, r, c+1);
        }
        return;
    }
};

/*
Conclusion:
a middle level algorithm issue, caculate the number of islands in an input matrix. We can use dfs to caculate it.
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

Solution 2: BFS version

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        if(grid.size() == 0 || grid[0].size() == 0)
            return ret;
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++ret;
                    q.push(make_pair(i,j));
                    grid[i][j] = '0';
                    while(!q.empty())
                    {
                        auto p = q.front();
                        q.pop();
                        //grid[p.first][p.second] = '0'; cause the memory exceed limit
                        for(auto dir : dirs)
                        {
                            int x = p.first+dir.first;
                            int y = p.second+dir.second;
                            if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1')
                                continue;
                            else
                            {
                                q.push(make_pair(x,y));
                                grid[x][y] = '0';
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
    
};


Solution #3  Union-Find

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<int> parent(m*n, 0);
        int count = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                    parent[i*n+j] = i*n+j;
                }
            }
        }
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    for(auto dir : dirs)
                    {
                        int x = i + dir.first;
                        int y = j + dir.second;
                        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0')
                            continue;
                        int p1 = find(parent, i*n+j);
                        int p2 = find(parent, x*n+y);
                        if(p1 != p2)
                        {
                            parent[p2] = p1;
                            --count;
                        }
                    }
                }
            }
        }
        return count;
    }
    
    
    int find(vector<int>& parent, int idx)
    {
        while(parent[idx] != idx)
            idx = parent[idx];
        return idx;
    }
   
};
