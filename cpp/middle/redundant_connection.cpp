class Solution {
public:
    
    int find_func(vector<int>& parent, int x)
    {
        if(parent[x] == x)
            return x;
        while(parent[x] != x)
            x = parent[x];
        return x;
    }

    void union_func(vector<int>& parent, int x, int y)
    {
        int parx = find_func(parent, x);
        int pary = find_func(parent, y);
        if(parx != pary)
            parent[parx] = pary;
    }
    
    /* union find algorithm */
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        if(edges.size() == 0)
            return {};
        vector<int> parent(n+1, 0);
        for(int i = 0; i <=n; ++i)
            parent[i] = i;
        for(auto edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            int parx = find_func(parent, x);
            int pary = find_func(parent, y);
            if(parx == pary)
                return edge;
            else
                union_func(parent, x, y);
        }
    }
    
    
};


/*
Conclusion: typical union-find function algorithm issue.
Time Complexity is: O(n)
space complexity is: O(n)

*/
