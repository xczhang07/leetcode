class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> ret;
        if(m == 0 || n == 0) return ret;
        int cnt = 0;
        vector<int> roots(m*n, -1);
        vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        for(int i = 0; i < positions.size(); ++i)
        {
            int root_id = n*positions[i].first + positions[i].second;
            if(roots[root_id] == -1)
            {
                roots[root_id] = root_id;
                cnt++;
            }
            
            for(auto dir : dirs)
            {
                int x = positions[i].first + dir.first;
                int y = positions[i].second + dir.second;
                int curr_id = n*x + y;
                if(x < 0 || x >= m || y < 0 || y >= n || roots[curr_id] == -1)
                    continue;
                Union(roots, root_id, curr_id, cnt);
            }
            ret.push_back(cnt);
        }
        return ret;
    }
    
    void Union(vector<int>& roots, int idx1, int idx2, int& cnt)
    {
        int p1 = findRoot(roots, idx1);
        int p2 = findRoot(roots, idx2);
        
        if(p1 != p2)
        {
            roots[p2] = p1;
            --cnt;
        }
        return;
    }
    
    int findRoot(vector<int>& roots, int idx)
    {
        while(roots[idx] != idx)
            idx = roots[idx];
        return idx;
    }
};
