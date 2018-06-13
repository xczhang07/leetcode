class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;
        dfs(rooms, visited, 0);
        for(int i = 0; i < visited.size(); ++i)
        {
            if(visited[i] == false)
                return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int idx)
    {
        for(int i = 0; i < rooms[idx].size(); ++i)
        {
            int j = rooms[idx][i];
            if(visited[j] == false)
            {
                visited[j] = true;
                dfs(rooms, visited, j);
            }
        }
        return;
    }
};


Conclusion: an middle level algorithm issue, actually, this is the graph travel issue. 
we create a bool vector to visit which room has been visited, if not visited, we dig into 
that room(with dfs algorithm for graph)

Time Complexity: O(n)
Space Complexity: O(n)
