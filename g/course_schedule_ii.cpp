class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ret;
        unordered_map<int,int> indegree;
        vector<vector<int>> graph(numCourses, vector<int>());
        for(auto e: prerequisites)
        {
            graph[e.second].push_back(e.first);
            indegree[e.first]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; ++i)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        if(q.size() == 0)
            return {};
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ret.push_back(front);
            indegree[front]--;
            for(int i = 0; i < graph[front].size(); ++i)
            {
                int child = graph[front][i];
                indegree[child]--;
                if(indegree[child] == 0)
                    q.push(child);
            }
        }
        if(ret.size() != numCourses)
            return {};
        
        return ret;
    }
    
   
    
};
