/* give a maze, start point, end point and find out the shortest path from start to end
  time complexity is: O(m*n)
  space complexity is: O(m*n)
*/

int getShortestPath(vector<vector<char>>& maze, pair<int,int> st, pair<int,int> end)
{
    if(maze.size() == 0 || maze[0].size() == 0)
        return 0;
    int path = 0;
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<int>> visited(m, vector<int>(n,-1));
    vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int steps = 0;
    queue<pair<int,int>> q;
    q.push(st);
    visited[st.first][st.second] = 0;
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        if(node.first == end.first && node.second == end.second)
            return visited[node.first][node.second];
        for(auto dir : dirs)
        {
            int nx = node.first + dir.first;
            int ny = node.second + dir.second;
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || maze[nx][ny] == '#'||visited[nx][ny] != -1)
                continue;
            visited[nx][ny] = visited[node.first][node.second]+1;
            q.push(make_pair(nx, ny));
        }
    }
    return 0;
}


/* 
test code as following:
output is: 22
*/

int main(int argc, const char* argv)
{

  vector<vector<char>> maze = {
        {'#', 'S', '#', '#', '#', '#', '#', '#', '.', '#'},
        {'.', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
        {'.', '#', '.', '#', '#', '.', '#', '#', '.', '#'},
        {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'#', '#', '.', '#', '#', '.', '#', '#', '#', '#'},
        {'.', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
        {'.', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
        {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
        {'.', '#', '#', '#', '#', '.', '#', '#', '#', '.'},
        {'.', '.', '.', '.', '#', '.', '.', '.', 'G', '#'},
    };
    
    pair<int,int> st = {0,1};
    pair<int,int> end = {9,8};
    cout<<"shortest path is: "<<getShortestPath(maze, st, end)<<endl;
    return 0;
  
}
