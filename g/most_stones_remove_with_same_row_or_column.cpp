On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Example 3:

Input: stones = [[0,0]]
Output: 0
 

Note:

1 <= stones.length <= 1000
0 <= stones[i][j] < 10000


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        if(stones.size() == 0)
            return 0;
        int n = stones.size();
        int cnt = n;
        vector<int> parent(n, 0);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    int p1 = find(parent, i);
                    int p2 = find(parent, j);
                    /* union */
                    if(p1 != p2)
                    {
                        parent[p2] = p1;
                        cnt--;
                    }
                }
            }
        }
        return n-cnt;
    }
    
    int find(vector<int>& parent, int idx)
    {
        while(parent[idx] != idx)
        {
            idx = parent[idx];
        }
        return idx;
    }
};
