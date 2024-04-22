class Solution {
public:
    bool dfs(vector<vector<int>>& graph, unordered_set<int>& visited, int curr, vector<bool>& hasApple, int& minTime) {
        visited.insert(curr);
        bool found = hasApple[curr];
        for(int& next: graph[curr]) {
           if(!visited.count(next)) {
                if(dfs(graph, visited, next, hasApple, minTime)) {
                    found = true;
                    minTime += 2;
                }
           }
        }
        return found;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n, vector<int>());
        for(auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int minTime = 0;
        unordered_set<int> visited;
        dfs(graph, visited, 0, hasApple, minTime);
        return minTime;
    }
};
