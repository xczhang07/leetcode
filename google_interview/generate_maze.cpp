第二轮：tech lead老爷爷，设计一个迷宫生成算法，input是迷宫的长，宽，还有起点 终点坐标，返回整个maze，要求必须随机生成，
且起点到终点有且只有一条路，且function run一次一定会生成一个valid的迷宫，不会出错，老爷爷给了一点小hint，我脑子里顿时冒出来一个bfs的解，
一气呵成写完了，老爷爷看着很满意，说这就是最优解，稍微优化了下代码，还剩10分钟左右闲聊...


#include<iostream>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<random>

using namespace std;

vector<pair<int,int>> randomGenerateDirection()
{
    
    vector<pair<int,int>> dirs = {{0,-1}, {0,1}, {1,0}, {-1,0}};
    vector<pair<int,int>> random_arr;
    int cnt = 0;
    while(cnt < 4)
    {
        cnt++;
        int idx = rand()%dirs.size();
        random_arr.push_back(dirs[idx]);
        dirs.erase(dirs.begin()+idx);
    }
    return random_arr;
}

bool generateMazeHelper(vector<vector<char>>& maze, int r, int c, pair<int,int>& end)
{
    if(r == end.first && c == end.second)
        return true;
    vector<pair<int,int>> dirs = randomGenerateDirection();
    bool ret = false;
    
    for(auto d: dirs)
    {
        int nx = r + d.first;
        int ny = c + d.second;
        if(nx < 0 || ny < 0 || nx >= maze.size() || ny >= maze[0].size())
            continue;
        if(maze[nx][ny] != 'w')
            continue;
        maze[nx][ny] = 'p';
        bool ret = generateMazeHelper(maze, nx, ny, end);
        if(ret)
            return true;
        maze[nx][ny] = 'w';
    }
    return false;
}

vector<vector<char>> generateMaze(int m, int n, pair<int,int> start, pair<int,int> end)
{
    vector<vector<char>> maze(m, vector<char>(n, 'w'));
    maze[start.first][start.second] = 'p';
    generateMazeHelper(maze, start.first, start.second, end);
    return maze;
}

int main()
{
    srand(time(0));
    pair<int,int> start = {1,1};
    pair<int,int> end = {4,4};
    vector<vector<char>> maze = generateMaze(5, 5, start, end);
    for(int i = 0; i < maze.size(); ++i)
    {
        for(int j = 0; j < maze[i].size(); ++j)
            cout<<maze[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
