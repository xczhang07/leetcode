class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> m;
        vector<int> dp(stones.size(), 0);
        m[0].insert(0);
        int k = 0;
        for(int i = 0; i < stones.size(); ++i)
        {
            while(dp[k]+1 < stones[i]-stones[k])
                ++k;
            for(int j = k; j < i; ++j)
            {
                int t = stones[i]-stones[j];
                if(m[j].count(t-1) || m[j].count(t) || m[j].count(t+1))
                {
                    m[i].insert(t);
                    dp[i] = max(dp[i], t);
                }
            }
        }
        return dp.back() > 0;
    }
};
