vector<int> getOrder(vector<vector<int>> preferenceList)
{
    vector<int> order;
    if(preferenceList.size() == 0)
        return order;
    unordered_map<int, unordered_set<int>> graph;
    unordered_map<int,int> indegree;
    /* build graph */
    for(int i = 0; i < preferenceList.size(); ++i)
    {
        vector<int> l = preferenceList[i];
        for(int j = 0; j < l.size()-1; ++j)
        {
            int from = l[j];
            int to = l[j+1];
            if(!graph.count(from))
            {
                indegree[from] = 0;
                graph[from] = unordered_set<int>();
            }
            if(!indegree.count(to))
            {
                indegree[to] = 0;
                graph[to] = unordered_set<int>();
            }
            if(!graph[from].count(to))
            {
                indegree[to]++;
                graph[from].insert(to);
            }
        }
    }
    
    /* topological sort */
    queue<int> q;
    for(auto in : indegree)
    {
        if(in.second == 0)
            q.push(in.first);
    }
    
    /* invalid input */
    if(q.size() == 0)
        return order;
    
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        order.push_back(top);
        indegree[top]--;
        for(auto n: graph[top])
        {
            indegree[n]--;
            if(indegree[n] == 0)
                q.push(n);
        }
    }
    
    /* invalid input check */
    if(order.size() != graph.size())
        return {};
    
    return order;
}
