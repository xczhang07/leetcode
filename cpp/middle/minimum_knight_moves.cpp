class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<pair<int,int>> dirs = {{-2,-1}, {-2,1}, {-1,2}, {1,2},
                                     {2,1}, {2,-1}, {1,-2}, {-1,-2}};
        vector<vector<bool>> visited(1000, vector<bool>(1000, false)); // because |x| + |y| = 300, we give the number to improve the efficiency.
        queue<pair<pair<int,int>, int>> q;
        q.push({{500,500},0});
        visited[500][500] = true;
        x += 500;
        y += 500;
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            if(top.first.first == x && top.first.second == y) {
                return top.second;
            }
            for(auto dir : dirs) {
                int new_x = top.first.first + dir.first;
                int new_y = top.first.second + dir.second;
                if(visited[new_x][new_y]) {
                    continue;
                }
                visited[new_x][new_y] = true;
                q.push({{new_x,new_y}, top.second+1});
            }
        }
        return 0;
    }
};
