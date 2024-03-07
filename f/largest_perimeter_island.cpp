Question Link: https://leetcode.com/discuss/interview-question/535473/Facebook-or-Phone-or-Largest-Perimeter-Island

Find the largest perimeter of an island given a 2 dimensional array of 1's and 0's representing land and water respectively.

Land = 1
Water = 0
Island = contiguous 1's that are adjacent to other 1's to the left, right, up, or down

Edge of an island = any 1 that is adjacent to a 0 OR grid boundary to the left, right, up, or down

Perimeter = total # of 1's on the edge of an island

Example 1:

Input:
[[1, 0, 1, 1, 1],
 [1, 0, 1, 1, 1],
 [0, 1, 0, 1, 1]]

Output: 7 (Island on the right)
Example 2:

Input:
[[0, 0, 0, 0, 0, 0, 0],
 [0, 1, 0, 1, 1, 1, 0],
 [0, 1, 0, 1, 1, 1, 0],
 [0, 0, 1, 1, 1, 1, 0],
 [0, 0, 0, 0, 0, 0, 0]]

Output: 9 (Island on the right)

BFS version:

int largestPerimeterIsland(vector<vector<int>>& islands) {
  int largest_perimeter = 0;
  int m = islands.size();
  int n = islands[0].size();
  vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (islands[i][j] == 1) {
        islands[i][j] = 2;
        int perimeter = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
          pair<int, int> top = q.front();
          q.pop();
          bool is_edge = false;
          for (auto dir : dirs) {
            int nx = top.first + dir.first;
            int ny = top.second + dir.second;
            if (nx < 0 || ny < 0 || nx > m - 1 || ny > n - 1 ||
                islands[nx][ny] == 0) {
              is_edge = true;
            } else if (islands[nx][ny] == 2) {
              continue;
            } else {
              islands[nx][ny] = 2;
              q.push({nx, ny});
            }
          }
          if (is_edge) {
            perimeter++;
          }
        }
        largest_perimeter = std::max(largest_perimeter, perimeter);
      }
    }
  }
  return largest_perimeter;
}
