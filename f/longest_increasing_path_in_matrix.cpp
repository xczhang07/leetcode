Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: 
left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Time Complexity is: O(m*n)
Space Complexity is: O(m*n)

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
