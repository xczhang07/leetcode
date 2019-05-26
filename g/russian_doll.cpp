class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size() == 0)
            return 0;
        int ret = 0;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n, 1);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second)
                    dp[i] = max(dp[i], dp[j]+1); 
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
