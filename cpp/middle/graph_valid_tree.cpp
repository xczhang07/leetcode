class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        /* construct graph according to the input edges */
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);
        for(auto e: edges)
        {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }
        bool ret = hasCycle(graph, visited, 0, -1); /* we do not iterate every node because if the input graph is a tree
        all nodes should be connected */
        if(ret)
            return false;
        for(auto e : visited)
            if(!e) return false;
        return true;
    }
    
    bool hasCycle(vector<vector<int>>& graph, vector<bool>& visited, int idx, int parent)
    {
        if(visited[idx])
            return true;
        visited[idx] = true;
        for(int i = 0; i < graph[idx].size(); ++i)
        {
            if(!visited[graph[idx][i]])
            {
                if(hasCycle(graph, visited, graph[idx][i], idx))
                    return true;
            }
            else
            {
                if(parent != graph[idx][i])
                    return true;
            }
        }
        return false;
    }
};

/*
Conclusion:
an middle level issue, undirected graph travel implementation, for the parent parameter:
https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
Time Complexity: O(V+E)
Space Complexity: O(V)

*/

