class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        unordered_set<string> s;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    string path;
                    dfs(grid, i, j, path, 'x');
                    if(path.size() > 0)
                        s.insert(path);
                }
            }
        }
        return s.size();
        
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, string& path, char dir)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if(grid[i][j] == 1)
        {
            grid[i][j] = 0;
            path.push_back(dir);
            dfs(grid, i-1, j, path, 'u');
            dfs(grid, i+1, j, path, 'd');
            dfs(grid, i, j-1, path, 'l');
            dfs(grid, i, j+1, path, 'r');
            path.push_back('b');
            return;
        }
    }
};
