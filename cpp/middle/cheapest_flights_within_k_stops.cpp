DFS version
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int,int>>> g;
        buildGraph(flights, g);
        int min_money = INT_MAX;
        int total_money = 0;
        vector<bool> visited(n, false);
        visited[src] = true;
        dfs(g, src, dst, K+1, min_money, total_money, visited);
        return min_money == INT_MAX?-1:min_money;
    }
    
    void buildGraph(vector<vector<int>>& flights, unordered_map<int,vector<pair<int,int>>>& g)
    {
        for(int i = 0; i < flights.size(); ++i)
            g[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
    }
    
    void dfs(unordered_map<int,vector<pair<int,int>>>& g, int src, int dst, int k, int& min_money, int total_money, vector<bool>& visited)
    {
        if(k < 0)
            return;
        if(src == dst)
        {
            if(k >= 0)
            {
                min_money = min(min_money, total_money);
                return;
            }
        }
        
        for(int i = 0; i < g[src].size(); ++i)
        {
            if(visited[g[src][i].first] || total_money + g[src][i].second > min_money)
                continue;
            visited[g[src][i].first] = true;
            dfs(g, g[src][i].first, dst, k-1, min_money, total_money+g[src][i].second, visited);
            visited[g[src][i].first] = false;
        }
    }
};


BFS Solution:
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int,int>>> g;
        buildGraph(flights, g);
        int min_money = INT_MAX;
        int stop = 0;
        queue<pair<int,int>> q;
        q.push(make_pair(src, 0));
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; ++i)
            {
                auto t = q.front();
                q.pop();
                if(t.first == dst)
                    min_money = min(min_money, t.second);
                for(auto m : g[t.first])
                {
                    if(t.second + m.second < min_money)
                        q.push(make_pair(m.first, m.second+t.second));
                }
            }
            if(stop > K)
                break;
            ++stop;
        }
        return min_money == INT_MAX? -1: min_money;
    }
    
    void buildGraph(vector<vector<int>>& flights, unordered_map<int,vector<pair<int,int>>>& g)
    {
        for(int i = 0; i < flights.size(); ++i)
            g[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
    }
    
   
};
