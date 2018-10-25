class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), 0);
        for(int i = 0; i < graph.size(); ++i)
        {
            if(colors[i] == 0)
            {
                bool is_valid = dfs(graph, colors, i, 1);
                if(!is_valid)
                    return false;
            }
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int curr, int color)
    {
        if(colors[curr] != 0)
            return colors[curr] == color;
        colors[curr] = color;
        for(int i = 0; i < graph[curr].size(); ++i)
        {
            bool is_valid = dfs(graph, colors, graph[curr][i], color*-1);
            if(!is_valid)
                return false;
        }
        return true;
    }
};


/*

Time Complexity is: O(V+E)
Space Complexity is: O(V+E)

*/
