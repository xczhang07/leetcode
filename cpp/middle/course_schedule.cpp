class Solution {
   
   public:
   bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(prerequisites.size() == 0)
            return true;
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<bool> visited(numCourses, false);
       vector<bool> recur_path(numCourses, false);
       /* construct the graph according to the prerequisites input */
       for(auto e: prerequisites)
           graph[e.second].push_back(e.first);
       for(int i = 0; i < numCourses; ++i)
       {
           if(!visited[i])
           {
               if(hasCycle(graph, visited, recur_path, i))
                   return false;
           }
       }
       return true;
        
    }
    
    bool hasCycle(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recur_path, int idx)
    {
        if(recur_path[idx])
            return true;
        if(visited[idx])
            return false;
        recur_path[idx] = true;
        visited[idx] = true;
        for(int i = 0; i < graph[idx].size(); ++i)
        {
                bool ret = hasCycle(graph, visited, recur_path, graph[idx][i]);
                if(ret)
                    return true;
        }
        recur_path[idx] = false;
        return false;
    }
};

/*
Conclustion: a middle level algorithm issue, it is equal to find whether or not there is a cycle exist in a directed graph.
1. convert the inpute edges to graph.
2. create an array to record which component has been visited.
3. create an array to record in one recursive path, which nodes has been visited (used to detect whether or not a cycle exists
in the input graph)

Time Complexity: O(V*E)
Space Complexity: O(V)
*/
