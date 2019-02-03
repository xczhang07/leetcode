On leetcode, there are several algorithm issues which is very samiliar and related for matrix travel, we can use dfs to work
them out. following questions are similiar:

1. Number of Islands
https://leetcode.com/problems/number-of-islands/description/

2. Number of Distinct Islands
https://leetcode.com/problems/number-of-distinct-islands/description/

3. Max area of island
https://leetcode.com/problems/max-area-of-island/description/



Solution:
1. Iterate the input matrix. O(m*n)
2. If meet matrix[i][j] is 1, we have to go next level, investigate it deeper.
3. Inorder to avoid next time visit the same cell, we have to modify the matrix[i][j] from 1 to 0.
4. for different issue, we can do specific ops according to the requirements:
  4.1, for the number of island, just mark the cell has been visited, that should be OK.
  4.2, for the distinct island numbers, we have to record which direction the we move next step and also after each path down
    we have to insert the end signal.
  etc...

Time Complexity is: O(m*n)
Space Complexity is: O(m*n)


Number of Islands:

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

Number of Distinct Islands

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        unordered_set<string> s;
        
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    string island = "s";
                    serilizeIsland(grid, island, i, j);
                    s.insert(island);
                }
            }
        }
        return s.size();
    }
    
    void serilizeIsland(vector<vector<int>>& grid, string& island, int i, int j)
    {
        if(grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(auto d : dirs)
        {
            int nx = i + d.first;
            int ny = j + d.second;
            if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == 0)
                continue;
            if(d.first == -1 && d.second == 0)
                island.push_back('u');
            else if(d.first == 1 && d.second == 0)
                island.push_back('d');
            else if(d.first == 0 && d.second == -1)
                island.push_back('l');
            else if(d.first == 0 && d.second == 1)
                island.push_back('r');
            serilizeIsland(grid, island, nx, ny);
            island.push_back('e');
        }
        return;
    }
};



/* Solution for max area of island */
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int max_area = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    int tmp_area = 1;
                    caculate(grid, i, j, tmp_area);
                    max_area = max(max_area, tmp_area);
                }
            }
        }
        return max_area;
    }
    
    void caculate(vector<vector<int>>& grid, int i, int j, int& area)
    {
        if(grid[i][j] == 0)
            return;
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        grid[i][j] = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(auto d: dirs)
        {
            int nx = d.first + i;
            int ny = d.second + j;
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0)
                continue;
            caculate(grid, nx, ny, ++area);
        }
        return;
    }
};
