class Solution {
public:
     vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisties, vector<vector<int>>& queries) {
        vector<bool> result(queries.size(), false);
        vector<vector<int>> graph(n, vector<int>());
        queue<int> q;
        vector<vector<bool>> reach(n, vector<bool>(n, false));
        // Build the graph.
        for(auto& entry: prerequisties) {
            graph[entry[0]].push_back(entry[1]);
        }
        // BFS.
        for(int i = 0; i < n; ++i) {
            q.push(i);
            while(!q.empty()) {
                int course = q.front();
                q.pop();
                for(int j: graph[course]) {
                    if(reach[i][j] == false) {
                        reach[i][j] = true;
                        q.push(j);
                    }
                }
            }
        }
        for(int i = 0; i < queries.size(); ++i) {
            result[i] = reach[queries[i][0]][queries[i][1]];
        }
        return result;
    }
};
