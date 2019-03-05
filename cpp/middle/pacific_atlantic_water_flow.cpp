class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> ret;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return ret;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n,false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i)
        {
            pair<int,int> p1 = make_pair(i,0);
            pair<int,int> p2 = make_pair(i,n-1);
            pacific[p1.first][p1.second] = true;
            atlantic[p2.first][p2.second] = true;
            dfs(matrix, pacific, p1);
            dfs(matrix, atlantic, p2);
        }
        
        for(int i = 0; i < n; ++i)
        {
            pair<int,int> p1 = make_pair(0,i);
            pair<int,int> p2 = make_pair(m-1,i);
            pacific[p1.first][p1.second] = true;
            atlantic[p2.first][p2.second] = true;
            dfs(matrix, pacific, p1);
            dfs(matrix, atlantic, p2);
        }
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ret.push_back(make_pair(i,j));
            }
        }
        return ret;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& ocean, pair<int,int> p)
    {
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int m = matrix.size();
        int n = matrix[0].size();
        for(auto d : dirs)
        {
            int x = d.first + p.first;
            int y = d.second + p.second;
            if(x < 0 || x >= m || y < 0 || y >= n || ocean[x][y])
                continue;
            if(matrix[x][y] >= matrix[p.first][p.second])
            {
                ocean[x][y] = true;
                dfs(matrix, ocean, make_pair(x,y));
            }
        }
    }
};
