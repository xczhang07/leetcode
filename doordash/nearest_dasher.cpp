Question: https://www.1point3acres.com/bbs/thread-1043914-1-1.html

vector<int> getNearestDishdasher(vector<vector<char>>& cityMap,
                                 vector<pair<int, int>>& locations) {
  vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int m = cityMap.size();
  int n = cityMap[0].size();
  vector<int> nearestDist;
  for (auto location : locations) {
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    q.push({{location.first, location.second}, 0});
    visited[location.first][location.second] = true;
    while (!q.empty()) {
      auto top = q.front();
      q.pop();
      if (cityMap[top.first.first][top.first.second] == 'D') {
        nearestDist.push_back(top.second);
        break;
      }
      for (auto dir : dirs) {
        int nx = top.first.first + dir.first;
        int ny = top.first.second + dir.second;
        if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1 || visited[nx][ny] ||
            cityMap[nx][ny] == 'X') {
          continue;
        } else {
          visited[nx][ny] = true;
          q.push({{nx, ny}, top.second + 1});
        }
      }
    }
  }
  return nearestDist;
}
