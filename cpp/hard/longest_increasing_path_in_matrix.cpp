class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> cache(m, vector<int>(n, -1));
        int longest_path = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int path = dfs(matrix, cache, i, j);
                longest_path = max(longest_path, path);
            }
        }
        return longest_path;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& cache, int x, int y)
    {
        if(cache[x][y] != -1)
            return cache[x][y];
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,-1}, {0,1}};
        cache[x][y] = 1;
        for(auto d : dirs)
        {
            int nx = d.first + x;
            int ny = d.second + y;
            if(nx >= matrix.size()||nx < 0 || ny >= matrix[0].size() || ny < 0 || matrix[nx][ny] <= matrix[x][y])
                continue;
            cache[x][y] = max(cache[x][y], dfs(matrix, cache, nx, ny)+1);
        }
        return cache[x][y];
    }
};

Time Complexity is: O(m*n)
Space Complexity is: O(m*n)
