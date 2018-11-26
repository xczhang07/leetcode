class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.size() == 0 || maze[0].size() == 0)
            return false;
        int m = maze.size();
        int n = maze[0].size();
        bool flag = false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        canReach(maze, start[0], start[1], m, n, destination, flag, visited);
        return flag;
    }
    
    void canReach(vector<vector<int>>& maze, int r, int c, int& m, int& n, vector<int>& dest, bool& flag, 
                  vector<vector<bool>>& visited)
    {
        if(r < 0 || r >= m || c < 0 || c >= n) return;
        if(visited[r][c]) return;
        visited[r][c] = true;
        if(r == dest[0] && c == dest[1])
        {
            flag = true;
            return;
        }
        int t = r;
        vector<pair<int, int>> dirs;
        for(t; t >= 0 && maze[t][c] != 1; --t);
        dirs.push_back({t+1, c});
        t = r;
        for(t; t < m && maze[t][c] != 1; ++t);
        dirs.push_back({t-1, c});
        t = c;
        for(t; t >= 0 && maze[r][t] != 1; --t);
        dirs.push_back({r, t+1});
        t = c;
        for(t; t < n && maze[r][t] != 1; ++t);
        dirs.push_back({r, t-1});
        for(auto d : dirs)
        {
            canReach(maze, d.first, d.second, m, n, dest, flag, visited);
            if(flag)
                return;
        }
    }
};

/*
Time Complexity is: O(m*n)
Space Complexity is: O(m*n)
*/


Solution 2: BFS version

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.size() == 0 || maze[0].size() == 0)
            return false;
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<pair<int,int>> q;
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            if(t.first == destination[0] && t.second == destination[1])
                return true;
            for(auto dir : dirs)
            {
                int x = t.first;
                int y = t.second;
                while(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0)
                {
                    x += dir.first;
                    y += dir.second;
                }
                x -= dir.first;
                y -= dir.second;
                if(!visited[x][y])
                {
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
        return false;
    }

};
