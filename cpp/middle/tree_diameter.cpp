class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& graph, vector<bool>& visited, int startNode, int& targetNode, int& dist, int tmpDist) {
        if(visited[startNode]) {
            return;
        }
        visited[startNode] = true;
        if(tmpDist > dist) {
            dist = tmpDist;
            targetNode = startNode;
        }
        for(int i = 0; i < graph[startNode].size(); ++i) {
            int nextNode = graph[startNode][i];
            if(!visited[nextNode]) {
                dfs(graph, visited, nextNode, targetNode, dist, tmpDist+1);
            }
        }
    }

    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        // build undirected graph
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int n = edges.size()+1;
        vector<bool> visited(n, false);
        // find the node which is the furtherest from node 0.
        int targetNode = 0;
        int dist = 0;
        dfs(graph, visited, 0, targetNode, dist, 0);
        for(int i = 0; i < n; ++i) {
            visited[i] = false;
        }
        int diameterNode = 0;
        dist = 0;
        dfs(graph, visited, targetNode, diameterNode, dist, 0);
        return dist;
    }
};
