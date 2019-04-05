
今天面了Airbnb，网上他家的面经不多，发一个攒RP求onsite。

/**
* Given: An array of strings where L indicates land and W indicates water,
*   and a coordinate marking a starting point in the middle of the ocean.
*
* Challenge: Find and mark the ocean in the map by changing appropriate Ws to Os.
*   An ocean coordinate is defined to be the initial coordinate if a W, and
*   any coordinate directly adjacent to any other ocean coordinate.
*
* void findOcean(String[] map, int row, int column);
*
* String[] map = new String[]{
*  "WWWLLLW",
*  "WWLLLWW",
*  "WLLLLWW"
* };
* printMap(map);
*
* STDOUT:
* WWWLLLW
* WWLLLWW
* WLLLLWW
*
* findOcean(map, 0, 1);
*
* printMap(map);
*
* STDOUT:
* OOOLLLW
* OOLLLWW
* OLLLLWW
*/

void findOcean(vector<vector<char>>& board, int i, int j)
{
	if (board.size() == 0 || board[0].size() == 0)
		return;
	int m = board.size();
	int n = board[0].size();
	if (board[i][j] == 'L')
		return;
	vector<pair<int, int>> dirs = { {0,1}, {0,-1}, {1,0 }, {-1,0} };
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	board[i][j] = 'O';
	while (!q.empty())
	{
		auto t = q.front();
		q.pop();
		for (auto dir : dirs)
		{
			int x = dir.first + t.first;
			int y = dir.second + t.second;
			if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'W')
				continue;
			board[x][y] = 'O';
			q.push(make_pair(x, y));
		}
	}
	return;
}
