class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);
        int components = 0;
        for(auto e : edges)
        {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }
        for(int i = 0; i < graph.size(); ++i)
        {
            if(visited[i])
                continue;
            ++components;
            dfs(graph, visited, i);
        }
        return components;
        
    }
    
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int idx)
    {
        if(visited[idx]) /* the node has been visited */
            return;
        visited[idx] = true;
        for(int i = 0; i < graph[idx].size(); ++i)
            dfs(graph, visited, graph[idx][i]);
        return;
    }
    
    
};


Conclusion: an middle algorithm issue, using dfs to do the graph travel can resolve this issue.

Time Complexity: O(V+E)
Space Complexity: O(V+E)
