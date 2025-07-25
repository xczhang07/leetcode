There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, 
your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
Note:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.


class Solution {
public:
    void buildGraph(vector<vector<int>>& flights, unordered_map<int, vector<pair<int,int>>>& g)
    {
        for(int i = 0; i < flights.size(); ++i)
            g[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        return;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(flights.size() == 0)
            return 0;
        
        unordered_map<int, vector<pair<int,int>>> graph;
        buildGraph(flights, graph);
        
        queue<pair<int,int>> q;
        q.push(make_pair(src, 0));
        int stops = 0;
        int min_price = INT_MAX;
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; ++i)
            {
                auto t = q.front();
                q.pop();
                if(t.first == dst)
                    min_price = min(min_price, t.second);
                for(int j = 0; j < graph[t.first].size(); ++j)
                {
                    if(t.second + graph[t.first][j].second < min_price)
                        q.push(make_pair(graph[t.first][j].first, t.second+graph[t.first][j].second));
                }
            }
            
            if(stops > K)
                break;
            ++stops;
        }
        
        if(min_price == INT_MAX)
            return -1;
        else
            return min_price;
    }
    
    
};

# Solution 2
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(flights.size() == 0) {
            return -1;
        }
        vector<vector<pair<int, int>>> adjList(n);
        // build the adj list
        for(vector<int>& f: flights) {
            int start = f[0];
            int end = f[1];
            int price = f[2];
            adjList[f[0]].push_back({end, price});
        }
        vector<int> minPrice(n, INT_MAX);
        queue<pair<int,int>> q;
        int stop = 0;
        q.push({src, 0});
        while(!q.empty() and stop <= k) {
            int size = q.size();
            while(size) {
                auto [city, cost] = q.front();
                q.pop();
                size -= 1;
                for(auto [neighbor, ticket]: adjList[city]) {
                    if(cost + ticket < minPrice[neighbor]) {
                        minPrice[neighbor] = cost + ticket;
                        q.push({neighbor, cost+ticket});
                    }
                }
            }
            stop += 1;
        }
        if(minPrice[dst] == INT_MAX) {
            return -1;
        }
        return minPrice[dst];
    }
