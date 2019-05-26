You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. 
You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
Example:

Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 7 

Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total 
             travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.

Seen this question in a real interview before?  

解题思路:
针对每一个building，对grid中，所有空地用BFS 进行距离计算。
要有一个距离场来记录到所有点的距离。

这道题的小trick，针对可以访问的点，用val表示，起始值是0，每访问一次自动减一，这样就省了visited array。。。

time complexity 是：
O(m*n*k)

space complexity 是：
O(m*n)

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) 
    {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sum(m, vector<int>(n,0));
        int ret = INT_MAX;
        int val = 0;
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    queue<pair<int,int>> q;
                    ret = INT_MAX;
                    auto dist = grid;
                    q.push(make_pair(i,j));
                    while(!q.empty())
                    {
                        auto top = q.front();
                        q.pop();
                        int x = top.first;
                        int y = top.second;
                        for(auto d : dirs)
                        {
                            int nx = x + d.first;
                            int ny = y + d.second;
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != val)
                                continue;
                            --grid[nx][ny];
                            dist[nx][ny] = dist[x][y]+1;
                            sum[nx][ny] += dist[nx][ny]-1;
                            ret = min(ret, sum[nx][ny]);
                            q.push(make_pair(nx, ny));
                        }
                    }
                    --val;
                }
            }
        }
        
        if(ret == INT_MAX)
            return -1;
        else
            return ret;
    }
};


