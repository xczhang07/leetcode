vector<vector<pair<int,int>>> assignBikeBFS(vector<vector<char>>& garage)
{
    vector<vector<pair<int,int>>> assignment;
    if(garage.size() == 0 || garage[0].size() == 0)
        return assignment;
    int n = garage.size();
    int m = garage[0].size();
    vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}};
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(garage[i][j] == 'P')
            {
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                visited[i][j] = true;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                while(!q.empty())
                {
                    auto t = q.front();
                    q.pop();
                    if(garage[t.first][t.second] == 'B')
                    {
                        assignment.push_back({{i,j},{t.first,t.second}});
                        garage[i][j] = 'X';
                        garage[t.first][t.second] = 'X';
                        break;
                    }
                    for(auto d: dirs)
                    {
                        int x = t.first + d.first;
                        int y = t.second + d.second;
                        if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y])
                            continue;
                        if(garage[x][y] == 'X')
                            continue;
                        visited[x][y] = true;
                        q.push(make_pair(x,y));
                    }
                }
            }
        }
    }
    
    return assignment;
}


/* test code */
int main()
{
    vector<vector<char>> garage =
    {
        {'P', 'O', 'P', 'O', 'O', 'P'},
        {'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'B', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O'},
        {'B', 'O', 'O', 'O', 'B', 'B'},
    };
    
    vector<vector<pair<int,int>>> assign = assignBikeBFS(garage);
    for(int i = 0; i < assign.size(); ++i)
    {
        cout<<"people: "<<"("<<assign[i][0].first<<","<<assign[i][0].second<<")"<<" assign bike "<<"("<<assign[i][1].first<<","<<assign[i][1].second<<")"<<endl;
    }
  return 0;
}
