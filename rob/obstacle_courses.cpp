# Question: https://www.1point3acres.com/bbs/thread-1035794-1-1.html


bool existPath(vector<vector<int>>& matrix) {
  if ( matrix.size() == 0 || matrix[0].size() == 0 ) {
    return false;
  }
  int m = matrix.size();
  int n = matrix[0].size();
  vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
  vector<pair<int, int>> jump_dirs = {{2,0}, {-2,0}, {0,2}, {0,-2}};
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  queue<pair<int, int>> q;
  q.push({0,0});
  visited[0][0] = true;
  while(!q.empty()) {
    auto node = q.front();
    q.pop();
    if(node.first == m-1 && node.second == n-1) {
      return true;
    }
    for(auto dir : dirs) {
      int x = node.first + dir.first;
      int y = node.second + dir.second;
      if(x < 0 || y < 0 || x > m-1 || y > n-1 || visited[x][y] || matrix[x][y] == 0) {
        continue;
      }
      q.push({x, y});
      visited[x][y] = true;
    }
    for(auto dir : jump_dirs) {
      int x = node.first + dir.first;
      int y = node.second + dir.second;
      if(x < 0 || y < 0 || x > m-1 || y > n-1 || visited[x][y] || matrix[x][y] == 0) {
        continue;
      }
      q.push({x, y});
      visited[x][y] = true;
    }
  }
  return false;
}
