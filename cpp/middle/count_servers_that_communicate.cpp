class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row(m, 0);
        vector<int> col(n,0);
        int ret = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) {
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1 and (row[i] > 1 or col[j] > 1)) {
                    ret += 1;
                }
            }
        }
        return ret;
    }
};
