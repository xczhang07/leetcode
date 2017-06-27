class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 1)
                {
                    if(i == 0 || grid[i-1][j] == 0)
                        ++perimeter;
                    if(i == grid.size()-1 || grid[i+1][j] == 0)
                        ++perimeter;
                    if(j == 0 || grid[i][j-1] == 0)
                        ++perimeter;
                    if(j == grid[0].size()-1 || grid[i][j+1] == 0)
                        ++perimeter;
                }
            }
        }
        return perimeter;
    }
};


Conclusion:
for each island, we caculate its four side seperately, if its adjacent is 0, plus 1.
