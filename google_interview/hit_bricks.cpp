打砖块儿问题，LC803

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{-1,0},{1,0}};
        int count = 0;
        vector<int> ret;
        for(int i = 0; i < hits.size(); ++i)
        {
            int r = hits[i][0];
            int c = hits[i][1];
            count = 0;
            grid[r][c] = 0;
            for(auto d : dirs)
            {
                int x = r + d.first;
                int y = c + d.second;
                if(x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                if(grid[x][y] == 0)
                    continue;
                if(!canReachTop(grid, m, n, x, y))
                    erase(grid, m, n, x, y, count);     
            }
            ret.push_back(count);
        }
        return ret;
    }
    
    void erase(vector<vector<int>>& grid, int& m, int& n, int x, int y, int& count)
    {
        vector<pair<int,int>> dirs = {{0,1},{0,-1}, {-1,0},{1,0}};
        ++count;
        grid[x][y] = 0;
        for(auto d : dirs)
        {
            int a = x + d.first;
            int b = y + d.second;
            if(a < 0 || a >= m || b < 0 || b >= n)
                continue;
            if(grid[a][b] == 0)
                continue;
            erase(grid, m, n, a, b, count);
        }
        return;
    }
    
    bool canReachTop(vector<vector<int>>& grid, int& m, int& n, int r, int c)
    {
        if(r == 0)
            return true;
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        
        int tmp = grid[r][c];
        grid[r][c] = 0;
        bool ret = false;
        for(auto d : dirs)
        {
            int x = r + d.first;
            int y = c + d.second;
            if(x < 0 || x >= m || y < 0 || y >= n)
                continue;
            if(grid[x][y] == 0)
                continue;
            ret = ret || canReachTop(grid, m, n, x, y);
            if(ret)
                break;
        }
        grid[r][c] = tmp;
        return ret;
    }
};
