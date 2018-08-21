class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ret;
        vector<bool> visited(numCourses, false);
        vector<bool> recur_path(numCourses, false);
        vector<vector<int>> graph(numCourses, vector<int>());
        for(auto e: prerequisites)
            graph[e.first].push_back(e.second);
        for(int i = 0; i < numCourses; ++i)
        {
            if(!visited[i])
            {
                bool finish = has_Cycle(graph, ret, visited, recur_path, i);
                if(finish)
                    return {};
            }
        }
        return ret;
    }
    
    bool has_Cycle(vector<vector<int>>& graph, vector<int>& ret, vector<bool>& visited, vector<bool>& recur_path, int idx)
    {
        if(recur_path[idx])
            return true;
        if(visited[idx])
            return false;
        visited[idx] = true;
        recur_path[idx] = true;
        for(int i = 0; i < graph[idx].size(); ++i)
        {
            bool is_cycle = has_Cycle(graph, ret, visited, recur_path, graph[idx][i]);
            if(is_cycle) /* if it has a cycle, it won't success */
                return true;
        }
        ret.push_back(idx);
        recur_path[idx] = false;
        return false;
    }
};

/*
Conclusion: an middle level algorithm issue, dfs on a graph, very similar with the question course schedule i
the same idea for finding whether or not there is a cycle exist in the graph. 

1. construct the graph according to the input edges(it is prerequisites in this case).
2. implement the dfs function, travel the graph with dfs method, detect whether or not there is any cycle at meantime.
3. at the end of dfs function, push the eleement into result vector.

Time Complexity: O(V*E)
Space Complexity: O(V)
*/
