class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) 
    {
        map<pair<string, string>, double> my_map;
        map<string, set<string>> adjs;
        vector<double> ret;
        /* build the graph and create look-up map */
        for(int i = 0; i < equations.size(); ++i)
        {
            auto e = equations[i];
            my_map[make_pair(e.first, e.second)] =  values[i];
            my_map[make_pair(e.second, e.first)] = 1.0 / values[i];
            adjs[e.first].insert(e.second);
            adjs[e.second].insert(e.first);
        }
        
        for(auto q : queries)
        {
            paths = {};
            dfs(adjs, q.first, q.second);
            if(paths.size() == 0)
                ret.push_back(-1);
            else
            {
                double multiply = 1.0;
                for(int i = 0; i < paths[0].size()-1; ++i)
                    multiply *= my_map[make_pair(paths[0][i], paths[0][i+1])];
                ret.push_back(multiply);
            }
        }
        return ret;
    }
    
private:    
    void dfs(map<string, set<string>>& adjs, string& start, string& end)
    {
        
        if(adjs.find(start) == adjs.end() || adjs.find(end) == adjs.end())
            return;
        set<string> visited;
        vector<string> path;
        dfsHelper(adjs, visited, start, end, path);
        return;
    }

    void dfsHelper(map<string, set<string>>& adjs, set<string>& visited, string& start, string& end, vector<string> path)
    {
        if(visited.find(start) == visited.end())
        {
            visited.insert(start);
            path.push_back(start);
        }
        if(adjs[start].find(end) != adjs[start].end())
        {
            path.push_back(end);
            paths.push_back(path);
            return;
        }
        for(auto e : adjs[start])
        {   
            if(visited.find(e) == visited.end())
                dfsHelper(adjs, visited, e, end, path);
        }
        return;
    }
    
    vector<vector<string>> paths;
    
};


Conclusion:
an middle level algorithm issue, however, it as a difficult level algorithm question...
