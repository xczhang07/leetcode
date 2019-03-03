感觉是面经里面推箱子问题

1. 推箱子游戏，就是推一个箱子，只能一推到底撞到墙之后才能换方向，给你一个矩形图，返回能否推到指定位置

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.size() == 0 || maze[0].size() == 0)
            return false;
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        q.push(make_pair(start[0], start[1]));
        visited[start[0]][start[1]] = true;
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            if(t.first == destination[0] && t.second == destination[1])
                return true;
            for(auto d : dirs)
            {
                int nx = t.first + d.first;
                int ny = t.second + d.second;
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny])
                    continue;
                while((nx >= 0 && nx < n && ny >= 0 && ny < m) && maze[nx][ny] == 0)
                {
                    nx += d.first;
                    ny += d.second;
                }
                nx -= d.first;
                ny -= d.second;
                if(!visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                }
            }
        }
        return false;
    }
};
