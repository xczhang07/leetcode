DFS solution:

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int ret = 0;
        int n = M.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i)
        {
            if(visited[i])  continue;
            if(dfs(M, visited, i))  ret++;
        }
        return ret;
    }
    
    bool dfs(vector<vector<int>>& M, vector<bool>& visited, int idx)
    {
        if(visited[idx])
            return false;
        visited[idx] = true;
        for(int i = 0; i < M.size(); ++i)
        {
            if(!M[idx][i] || visited[i])    continue;
            if(!dfs(M, visited, i)) return false;
        }
        return true;
    }
    
    
};

Conclusion:
一到中等难度的问题，这道题要求我们找出朋友圈的个数，并且朋友圈是可以传递的，打个比方，A和B是好友，B和C是好友，那么A和C即便不是好友，
但是他们也是一个朋友圈的。所以，对于这个问题，我们用dfs做就可以了，对于某个人，遍历他的好友，之后针对他的每个好友，再遍历好友的好友，这样就可以把
属于同一个朋友圈的人便利一遍， 同时，我们记录已经便利过的人，这样可以避免再次访问，之后将遍历过的朋友圈相加，我们就得到了朋友圈总数。
Time Complexity: O(n^2)
Space Complexity: O(n)

BFS Solution:

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int ret = 0;
        vector<bool> visited(n,false);
        queue<int> q;
        for(int i = 0; i < n; ++i)
        {
            if(visited[i]) continue;
            q.push(i);
            while(!q.empty())
            {
                int idx = q.front();
                visited[idx] = true;
                q.pop();
                for(int j = 0; j < n; ++j)
                {
                    if(!M[idx][j] || visited[j]) continue;
                    q.push(j);
                }
            }
            ++ret;
        }
        return ret;
    }
};

same time complexity and space complexity with DFS solution.