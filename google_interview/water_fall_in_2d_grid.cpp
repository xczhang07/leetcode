给一个二维数组，每个点的值代表高度，然后给一个点，问：往这个点上倒水的话，水是否能流到二维数组的边缘，很基础的BFS或者DFS来解，
然后让我自己给一些test case，然后问了一下在什么样的test case下DFS会比BFS更好。
follow up: 求出所有这个二维数组中水能流到边缘的点。

//BFS version:

vector<pair<int,int>> waterFlow(vector<vector<int>>& grid, pair<int, int> start)
{
	vector<pair<int, int>> points;
	if (grid.size() == 0 || grid[0].size() == 0)
		return points;
	vector<pair<int, int>> dirs = { {1,0},{-1,0},{0,-1},{0,1} };
	queue<pair<int, int>> q;
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> visited(m, vector<int>(n, 0));
	q.push(make_pair(start.first, start.second));
	visited[start.first][start.second] = 1;
	while (!q.empty())
	{
		int s = q.size();
		for (int i = 0; i < s; ++i)
		{
			auto t = q.front();
			q.pop();
			if (t.first == 0 || t.first == m - 1 || t.second == 0 || t.second == n - 1)
				points.push_back(make_pair(t.first, t.second));
			for (auto d : dirs)
			{
				int x = t.first + d.first;
				int y = t.second + d.second;
				if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]==1)
					continue;
				if (grid[x][y] <= grid[t.first][t.second])
				{	
					visited[x][y] = 1;
					q.push(make_pair(x, y));
				}
			}
		}
	}
	return points;
}


//DFS version:

void dfsHelper(vector<vector<int>>& grid, vector<vector<bool>>& visited, pair<int, int> p, vector<pair<int,int>>& ret)
{
	int m = grid.size();
	int n = grid[0].size();
	if (p.first == 0 || p.first == m - 1 || p.second == 0 || p.second == n - 1)
		ret.push_back(make_pair(p.first, p.second));
	vector<pair<int, int>> dirs = { {0,1}, {0,-1 }, {1,0}, {-1,0} };
	for (auto d : dirs)
	{
		int x = d.first + p.first;
		int y = d.second + p.second;
		if (x < 0 || x >= m || y < 0 || y >= n||visited[x][y])
			continue;
		if (grid[x][y] <= grid[p.first][p.second])
		{
			pair<int, int> next = make_pair(x, y);
			visited[x][y] = true;
			dfsHelper(grid, visited, next, ret);
		}
	}
	return;
}

vector<pair<int, int>> waterFlowDFS(vector<vector<int>>& grid, pair<int, int> p)
{
	vector<pair<int, int>> points;
	if (grid.size() == 0 || grid[0].size() == 0)
		return points;
	int m = grid.size(), n = grid[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	dfsHelper(grid, visited, p, points);
	return points;
}

//Test case:
int main
{
  vector<vector<int>> mountains =
	{
		{ 1,2,3,4,5 },
		{ 7,8,4,5,1 },
		{ 7,3,3,5,2 },
		{ 5,2,4,3,1 }
	};
	pair<int, int> pos = {1,2};
	vector<pair<int,int>> points = waterFlow(mountains, pos);
	cout << "BFS travel" << endl;
	if (points.size() == 0)
		cout << "can reach the border" << endl;
	else
	{
		cout << "the water can reach the following points: " << endl;
		for (int i = 0; i < points.size(); ++i)
			cout << "(" << points[i].first << " , " << points[i].second << ")" << " ";
		cout << endl;
	}

	points = waterFlowDFS(mountains, pos);
	cout << "DFS travel" << endl;
	if (points.size() == 0)
		cout << "can reach the border" << endl;
	else
	{
		cout << "the water can reach the following points: " << endl;
		for (int i = 0; i < points.size(); ++i)
			cout << "(" << points[i].first << " , " << points[i].second << ")" << " ";
		cout << endl;
	}
  return 0;
}
