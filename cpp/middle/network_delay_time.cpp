class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1, vector<pair<int, int>>());
        // build the adjacent list.
        for(auto& t: times) {
            int from = t[0];
            int to = t[1];
            int delay = t[2];
            adj[from].push_back({to, delay});
        }
        int minTravelTime = 0;
        vector<int> cost(n+1, INT_MAX);
        cost[k] = 0;
        queue<pair<int,int>> q;
        q.push({k, 0});
        while(!q.empty()) {
            int size = q.size();
            while(size) {
                auto node = q.front();
                q.pop();
                size -= 1;
                int from = node.first;
                int weight = node.second;
                for(auto& next: adj[from]) {
                    int target = next.first;
                    int delay = next.second;
                    // update the travel to the target minTime.
                    if(cost[target] > weight+delay) {
                        cost[target] = weight+delay;
                        q.push({target, cost[target]});
                    }
                }
            }
        }
        for(int i = 1; i < cost.size(); ++i) {
            minTravelTime = max(minTravelTime, cost[i]);
        }
        if(minTravelTime == INT_MAX) {
            return -1;
        }
        return minTravelTime;
    }
};

Time Complexity: O(V+E) 
Space Complexity: O(V)

V is node number, E is edge.
