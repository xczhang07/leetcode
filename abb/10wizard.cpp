/*
There are 10 wizards, 0-9, you are given a list that each entry is a list of wizards known by wizard.
Define the cost between wizards and wizard as square of difference of i and j.
To find the min cost between 0 and 9.
wizard[0] list: {1, 4, 5} wizard[4] list: {9} wizard 0 to 9 min distance is (0-4)^2+(4-9)^2=41
(wizard[0]->wizard[4]->wizard[9])
*/


// 1st version, get the minCost path and no keep track on the visited node(potential bug)
int wizardMinCost(vector<vector<int>>& wizards, int src, int dst)
{
    if (wizards.size() == 0)
        return 0;
    int min_cost = INT_MAX;
    queue<pair<vector<int>, pair<int, int>>> q;
    vector<int> path;
    path.push_back(src);
    q.push(make_pair(path, make_pair(src, 0)));
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; ++i)
        {
            auto t = q.front();
            q.pop();
            if (t.second.first == dst)
            {
                if (t.second.second < min_cost)
                {
                    min_cost = t.second.second;
                    path = t.first;
                }
            }
            for (int j = 0; j < wizards[t.second.first].size(); ++j)
            {
                int m = wizards[t.second.first][j];
                int k = t.second.first;
                vector<int> tmp = t.first;
                if (pow(m - k, 2) + t.second.second < min_cost)
                    tmp.push_back(m);
                q.push(make_pair(tmp, make_pair(m, pow(m-k, 2)+t.second.second)));
            }
        }
    }
    
    cout << "the shortest path as following:" << endl;
    for (int i = 0; i < path.size(); ++i)
        cout << path[i] << " ";
    cout << endl;
    return min_cost;
}

// Version2: maintain an length is 10 minCost array, added the logic to handle the visited node
int wizardMinCostV2(vector<vector<int>>& wizards, int src, int dst) {
    if(wizards.size() == 0) {
        return 0;
    }
    if(src < 0 or src > 9 or dst < 0 or dst > 9) {
        return 0;
    }
    vector<int> minCostVec(10, INT_MAX);
    minCostVec[src] = 0;
    queue<pair<int,int>> q;
    q.push({src, 0});
    unordered_set<int> visited;
    // Define an visited set to keep track of the visited wizard
    visited.insert(src);
    // BFS traversal the queue.
    while(!q.empty()) {
        int size = q.size();
        while(size) {
            size -= 1;
            auto top = q.front();
            q.pop();
            int currWizard = top.first;
            int cost = top.second;
            for(int i = 0; i < wizards[currWizard].size(); ++i) {
                int neighborWizard = wizards[currWizard][i];
                int newCost = cost + (neighborWizard-currWizard)*(neighborWizard-currWizard);
                if(newCost < minCostVec[neighborWizard]) {
                    minCostVec[neighborWizard] = newCost;
                    if(visited.find(neighborWizard) == visited.end()) {
                        q.push({neighborWizard, newCost});
                    }
                }
            }
        }
    }
    return minCostVec[dst];
}

