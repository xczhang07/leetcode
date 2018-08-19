class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret;
        if(edges.size() == 0)
        {
            ret.push_back(0);
            return ret;
        }
        vector<unordered_set<int>> graph(n, unordered_set<int>());
        queue<int> q; // used to record the node which degree is 1
        /* construct the graph according to the input edges */
        for(auto e: edges)
        {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        
        for(int i = 0; i < n; ++i)
        {
            if(graph[i].size() == 1)
                q.push(i); /* push the node which has 1 degree into queue */
        }
        
        while(n > 2) /* bfs + topological sort */
        {
            int m = q.size();
            for(int i = 0; i < m; ++i)
            {
                int node = q.front();
                q.pop();
                for(auto j: graph[node])
                {
                    graph[j].erase(node);
                    if(graph[j].size() == 1) /* after remove target node, insert the rest 1 degree node */
                        q.push(j); 
                }
            }
            n -= m;
        }
        
        while(!q.empty())
        {
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};
/*
Conclusion: middle level graph issue, read the issue carefully, then understand what is the meaning of "min height tree".
构成的树深度最大的情况发生在所有点位于一条链上，此时深度为 n/2 或 n/2+1 ，这取决于n的奇偶性。
the root of the min height tree is the middle one or two nodes of the longest path of the input graph.
step1, create graph according to the given edges.
step2, add the degree 1's node into queue(unordered_set() will keep the unique neighbor)
step3, take off all the 1 degree nodes, then keep add the remaining 1 degree node into q(need to update the adj list) until the node number less than 2
step4, push the node in queue into ret array

Time Complexity: O(v+E)
Space Complexity: O(n)

*/
