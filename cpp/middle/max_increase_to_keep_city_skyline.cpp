class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ret = 0;
        if(grid.size() == 0 || grid[0].size() == 0)
            return ret;
        int rowLen = grid.size();
        int colLen = grid[0].size();
        vector<int> maxRaw(rowLen, INT_MIN); /* the vector to store the max numbers of each raw */
        vector<int> maxCol(colLen, INT_MIN); /* the vector to store the max numbers of each col */
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                maxRaw[i] = max(maxRaw[i], grid[i][j]);
                maxCol[i] = max(maxCol[i], grid[j][i]);
            }
        }
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] < maxRaw[i] && grid[i][j] < maxCol[j])
                    ret += (min(maxRaw[i], maxCol[j]) - grid[i][j]);
            }
        }
        return ret;
    }
};


Conclusion: 
an middle level algorithm issue of leetcode. 

Idea: for each grid[i][j], it can't be higher than the maxim of raw i and maxim of col j, thus, its increase value should be: min(maxRaw[i], maxCol[j])-grid[i][j]

Time Complexity: O(m*n)
Space Complexity: O(n)


