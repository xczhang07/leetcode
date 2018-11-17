class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 0 || n == 0) return matrix;
        queue<pair<int,int>> q;
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                    q.push({i,j});
                else
                    matrix[i][j] = INT_MAX;
            }
        }
        
        while(!q.empty())
        {
            auto e = q.front();
            q.pop();
            for(auto d : dirs)
            {
                int x = e.first + d.first;
                int y = e.second + d.second;
                if(x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                if(matrix[x][y] <= matrix[e.first][e.second])
                    continue;
                matrix[x][y] = matrix[e.first][e.second]+1;
                q.push(make_pair(x, y));
            }
        }
        return matrix;
    }
};


/*
Time Complexity is: O(m*n)
Space Complexity is: O(m*n)

http://www.cnblogs.com/grandyang/p/6602288.html
*/
