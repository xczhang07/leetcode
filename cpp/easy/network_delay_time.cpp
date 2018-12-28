Time Exceed Limit version, dfs + hash_table:

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(times.size() == 0 || times[0].size() == 0)
            return 0;
        unordered_map<int, vector<pair<int, int>>> g;
        vector<bool> visited(N+1, false);
        unordered_map<int,int> dist;
        int path = 0;
        int delay = INT_MIN;
        /* construct the graph according to the input */
        for(int i = 0; i < times.size(); ++i)
            g[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        dfs(g, dist, visited, K, path);
        
        if(dist.size() != N)
            return -1;
        for(auto d : dist)
            delay = max(delay, d.second);
        
        if(delay == 0)
            return -1;
        return delay;
    }
    
    void dfs(unordered_map<int,vector<pair<int, int>>>& g, unordered_map<int, int>& dist, 
             vector<bool>& visited, int node, int path)
    {
        if(visited[node])
            return;
        if(dist.count(node))
            dist[node] = min(dist[node], path);
        else
            dist[node] = path;
       
        for(int i = 0; i < g[node].size(); ++i)
        {
            if(!dist.count(g[node][i].first) || dist[g[node][i].first] > path + g[node][i].second)
            {
                visited[node] = true;
                dfs(g, dist, visited, g[node][i].first, path+g[node][i].second);
                visited[node] = false;
            }
        }
        return;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(times.size() == 0 || times[0].size() == 0)
            return 0;
        int res = 0;
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 1; i < N; ++i) {
            for (auto e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        for (int i = 1; i <= N; ++i) {
            res = max(res, dist[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
    
    
};
