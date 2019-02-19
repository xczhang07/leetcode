class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0)
            return true;
        if(wordDict.size() == 0)
            return false;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, 0);
        dp[0] = true;
        for(int i = 0; i <= s.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                string sub_str = s.substr(j, i-j);
                if(dp[j] && set.count(sub_str))
                    dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};
