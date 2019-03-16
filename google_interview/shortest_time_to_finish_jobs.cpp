有n个job和p个工人，job之间有dependency，写一个函数来
schedule jobs，并计能完成所有工作的最短时间（每个job消耗一个unit的时间）

int shortestFinshJobs(vector<vector<int>>& jobs, int n, int p)
{
	if (jobs.size() == 0)
		return -1;
	int times = 0;
	unordered_map<int, int> indegree;
	for (int i = 0; i < jobs.size(); ++i)
	{
		for (int j = 0; j < jobs[i].size(); ++j)
			indegree[jobs[i][j]]++;
	}

	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	if (q.size() == 0)
		return -1;

	while (!q.empty())
	{
		int s = q.size();
		int m = min(p, s);
		for (int i = 0; i < m; ++i)
		{
			int t = q.front();
			q.pop();
			indegree[t]--;
			for (int j = 0; j < jobs[t].size(); ++j)
			{
				int nj = jobs[t][j];
				indegree[nj]--;
				if (indegree[nj] == 0)
					q.push(nj);
			}
		}
		++times;
	}

	return times;
}


int main()
{

vector<vector<int>> jobs = { {1},{2,3,4},{5,6},{7,8},{9,10,11},{},{},{},{},{},{},{} };

	cout<<"shortest time to finish those jobs: "<<shortestFinshJobs(jobs, 12, 3)<<endl;
  
  return 0;
}
