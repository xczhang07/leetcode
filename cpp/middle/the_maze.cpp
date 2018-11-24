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
