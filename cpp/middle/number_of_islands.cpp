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
