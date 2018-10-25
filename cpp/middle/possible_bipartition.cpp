class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N, vector<int>());
        for(int i = 0; i < dislikes.size(); ++i)
        {
            graph[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            graph[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }
        vector<int> colors(N,0);
        for(int i = 0; i < graph.size(); ++i)
        {
            if(colors[i] == 0)
            {
                if(!dfs(graph, colors, i, 1))
                    return false;
            }
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int curr, int color)
    {
        if(colors[curr]!=0)
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
an middle level algorithm issue, using graph dfs traveling can resolve the issue.
Time Complexity is: O(V+E)
Space Complexity is: O(V+E)
*/
