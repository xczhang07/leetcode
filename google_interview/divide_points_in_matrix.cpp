
int dividePoint(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
{
	int d = (p.first - p1.first)*(p2.second - p1.second) - (p.second - p1.second)*(p2.first-p1.first);
	return d;
}

pair<vector<pair<int,int>>, vector<pair<int,int>>> dividePoints(vector<pair<int, int>>& points)
{
	pair<vector<pair<int,int>>, vector<pair<int,int>>> ret;
	if (points.size() <= 2)
		return ret;
	auto point1 = points[0];
	vector<pair<int, int>> up;
	vector<pair<int, int>> bottom;
	for (int i = 1; i < points.size(); ++i)
	{
		auto point2 = points[i];
		for (int i = 0; i < points.size(); ++i)
		{
			auto t = points[i];
			if ((t.first == point1.first && t.second == point1.second) || (t.first == point2.first && t.second == point2.second))
				continue;
			int d = dividePoint(point1, point2, t);
			if (d > 0)
				up.push_back(t);
			else
				bottom.push_back(t);
		}
		if (up.size() == bottom.size())
			return make_pair(up, bottom);
		else
		{
			up.clear();
			bottom.clear();
		}
	}
	return ret;
}

int main()
{
vector<pair<int, int>> points = { {1,1}, {2,2}, {2,3},{2,4},{-1,0},{-3,-4} };

	pair < vector<pair<int,int>>, vector<pair<int, int>> > partition = dividePoints(points);
	for (auto e : partition.first)
	{
		cout << "(" << e.first << "," << e.second << ")" << " ";
	}
	cout << endl;

	for (auto e : partition.second)
	{
		cout << "(" << e.first << "," << e.second << ")" << " ";
	}
	cout << endl;
return 0;
}
