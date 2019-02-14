int getIntersection(unordered_set<int> s1, unordered_set<int> s2)
{
    int ret = 0;
    for(auto e : s1)
    {
        if(s2.count(e))
            ++ret;
    }
    return ret;
}

int getTriangles(vector<pair<int,int>>& edges)
{
    int t = 0;
    if(edges.size() <= 2)
        return 0;
    unordered_map<int,unordered_set<int>> g;
    for(auto e: edges)
    {
        g[e.first].insert(e.second);
        g[e.second].insert(e.first);
    }
    
    for(auto& e : g)
    {
        auto c1 = e.second;
        for(auto m: c1)
        {
            auto c2 = g[m];
            int ret = getIntersection(e.second, c2);
            t += ret;
            e.second.erase(m);
            g[m].erase(e.first);
        }
        
    }
    return t;
}
