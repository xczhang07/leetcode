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
