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

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) 
    {
        if(grid.size() == 0 || grid[0].size() == 0)
            return {};
        vector<int> drops;
        drops.resize(hits.size());
        int m = grid.size();
        int n = grid[0].size();
        vector<int> parent(m*n, -1);
        vector<int> count(m*n, 1);
        vector<int> connect(m*n, 0);
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        /* initialize */
        for(int i = 0; i < n; ++i)
            connect[i] = 1;
        for(int i = 0; i < hits.size(); ++i)
            grid[hits[i][0]][hits[i][1]] -= 1;
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] != 1)
                    continue;
                if(i+1 < m && grid[i+1][j] == 1)
                {
                    int p1 = find(parent, i*n+j);
                    int p2 = find(parent, (i+1)*n+j);
                    if(p1 != p2)
                    {
                        parent[p2] = p1;
                        count[p1] += count[p2];
                        connect[p1] = connect[p1] | connect[p2];
                        connect[p2] = connect[p1] | connect[p2];
                    }
                }
                if(j + 1 < n && grid[i][j+1] == 1)
                {
                    int p1 = find(parent, i*n+j);
                    int p2 = find(parent, i*n+j+1);
                    if(p1 != p2)
                    {
                        parent[p2] = p1;
                        count[p1] += count[p2];
                        connect[p1] = connect[p1] | connect[p2];
                        connect[p2] = connect[p1] | connect[p2];
                    }
                }
            }
        }
        
        
        for(int i = hits.size()-1; i >= 0; --i)
        {
            int x = hits[i][0];
            int y = hits[i][1];
            int a = find(parent, x*n+y);
            int cnt = 0;
            if(++grid[x][y] != 1)
                continue;
            for(auto d : dirs)
            {
                int nx = x + d.first;
                int ny = y + d.second;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1)
                    continue;
                int b = find(parent, nx*n + ny);
                if(a == b)
                    continue;
                if(!connect[b])
                    cnt += count[b];
                
                parent[b] = a;
                count[a] += count[b];
                connect[a] = connect[a] | connect[b];
                connect[b] = connect[a] | connect[b];
            }
            if(connect[a])
                drops[i]=cnt;
        }
        
        return drops;
    }
    
    int find(vector<int>& parent, int idx)
    {
        while(parent[idx] != -1)
        {
            idx = parent[idx];
        }
        return idx;
    }
};
