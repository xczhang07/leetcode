输入(String[][] travel, String[][] point)
输出：int score
travel的形式是[["start","3","A],["A","4","B"],["B","5","END1"]]

第一个String为出发点，第二个为从某个点到下一个点的cost，第三个String为结束点，可以想象为滑雪的人从“start"到"A"需要的cost为3
point的形式为[["A","5"],["B","6"],["END","3"]]
代表到达每一个点的reward
所要求的是从start到end的最大score，注意end点可能有很多个，start是固定的
score的计算方法是reward-cost
比如说从start到A，cost是3，reward是5，那么A的score就是5-3=2，当然只是举个例子，A的score应该是所有到达A的方式里最大的那个。
我的做法是先用Hashmap把cost, reward保存下来，然后再用一个Hashmap存每个点的score，做bfs一直到END，可以找到最大的score。
Follow up 是要求打印从start到end的路径，就是使得score最大的那条路。
做法是用一个parent把每个点的parent记录下来，再从END一路找parent回去，找到start了就是我们要找的路径。

int skyingLargestScore(string start, vector<string> end, vector<vector<string>> travel, unordered_map<string,int> score, vector<string>& path)
{
	if (travel.size() == 0 || score.size() == 0)
		return 0;

	unordered_map<string, vector<pair<string, int>>> graph;
	unordered_set<string> s(end.begin(), end.end());
	/* construct the graph */
	for (int i = 0; i < travel.size(); ++i)
		graph[travel[i][0]].push_back(make_pair(travel[i][2], stoi(travel[i][1])));
	
	path.push_back("start");
	int max_score = 0;
	queue<pair<vector<string>, pair<string, int>>> q;
	q.push({path, make_pair("start", 0)});

	while (!q.empty())
	{
		int n = q.size();
		for (int i = 0; i < n; ++i)
		{
			auto t = q.front();
			q.pop();
			string dst = t.second.first;
			if (s.count(dst))
			{
				if (t.second.second > max_score)
				{
					max_score = t.second.second;
					path = t.first;
				}
			}
			for (int j = 0; j < graph[dst].size(); ++j) 
			{
				vector<string> tmp = t.first;
				string neighbor = graph[dst][j].first;
				int sc = t.second.second - graph[dst][j].second + score[neighbor];
				tmp.push_back(neighbor);
				q.push({ tmp,{ neighbor, sc } });
			}
		}
	}
	cout << "max_score is: " << max_score << endl;
	return max_score;
}

int main()
{
  vector<vector<string>> skipTrip;
	skipTrip.push_back({"start", "4", "A"});
	skipTrip.push_back({"A", "4", "B"});
	skipTrip.push_back({"B", "5","end1"});
	skipTrip.push_back({ "start", "2","C" });
	skipTrip.push_back({ "C", "3","end1" });
	skipTrip.push_back({"start", "2", "end2"});

	unordered_map<string, int> skipScore;
	skipScore["A"] = 1;
	skipScore["B"] = 30;
	skipScore["C"] = 10;
	skipScore["end1"] = 7;
	skipScore["end2"] = 35;

	vector<string> ending;
	ending.push_back("end1");
	ending.push_back("end2");

	string start = "start";
	vector<string> path;
	cout << skyingLargestScore(start, ending, skipTrip, skipScore, path) << endl;
	cout << "output path is: " << endl;
	for (int i = 0; i < path.size(); ++i)
		cout << path[i] << " ";
	cout << endl;
  return 0;
}


int getHighestSkyingScoreV2(vector<string>& end, vector<tuple<string, int, string>>& costs, unordered_map<string, int>& rewards, vector<string>& path) {
    if(costs.size() == 0 or rewards.size() == 0 or end.size() == 0) {
        return 0;
    }
    unordered_set<string> dst(end.begin(), end.end());
    unordered_map<string, vector<pair<string, int>>> graph;
    int maxScore = INT_MIN;
    // build the graph based on the input.
    for(auto cost: costs) {
        string start = get<0>(cost);
        string arrival = get<2>(cost);
        int money = get<1>(cost);
        graph[start].push_back({arrival, money});
    }
    queue<pair<vector<string>, pair<string, int>>> q;
    q.push({{"start"}, {"start", 0}});
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; ++i) {
            auto node = q.front();
            q.pop();
            string currLocation = node.second.first;
            // if the current location in the dstination set, compute the highest score
            if(dst.count(currLocation)) {
                int score = node.second.second;
                if(score > maxScore) {
                    maxScore = score;
                    path = node.first;
                }
                continue;
            }
            // traverse the graph based on the current location
            for(int j = 0; j < graph[currLocation].size(); ++j) {
                string nextStation = graph[currLocation][j].first;
                vector<string> tmpPath = node.first;
                tmpPath.push_back(nextStation);
                int score = rewards[nextStation] - graph[currLocation][j].second;
                q.push({tmpPath, {nextStation, node.second.second+score}});
            }
        }
    }
    return maxScore;
}

