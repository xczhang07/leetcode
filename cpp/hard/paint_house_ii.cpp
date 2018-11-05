class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size() == 0 || costs[0].size() == 0)
            return 0;
        int n = costs.size(); /* n houses */
        int k = costs[0].size(); /* k colors */
        int min1 = -1, min2 = -1;
        int last1 = -1, last2 = -1;
        vector<vector<int>> dp = costs;
        for(int i = 0; i < n; ++i)
        {
            last1 = min1;
            last2 = min2;
            min1 = -1;
            min2 = -1;
            for(int j = 0; j < k; ++j)
            {
                if(j != last1)
                {
                    if(last1 >= 0)
                        dp[i][j] += dp[i-1][last1];
                }
                else
                {
                    if(last2 >= 0)
                        dp[i][j] += dp[i-1][last2];
                }
                if(min1 < 0 || dp[i][j] < dp[i][min1])
                {
                    min2 = min1;
                    min1 = j;
                }
                else if(min2 < 0 || dp[i][j] < dp[i][min2])
                    min2 = j;
            }
        }
        return dp.back()[min1];
    }
};

/*
a hard algorithm issue on leetcode.
Time Complexity is: O(m*n)
Space Complexity is: O(m*n)
reference link as following:
http://www.cnblogs.com/grandyang/p/5322870.html
*/
