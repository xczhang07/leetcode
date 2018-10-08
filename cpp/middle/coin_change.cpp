class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i)
        {
            for(int j = 0; j < coins.size(); ++j)
            {
                if(i >= coins[j])
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        if(dp[amount] > amount)
            return -1;
        else
            return dp[amount];
    }
};


/*
Conclusion, a middle level algorithm issue on leetcode, a classic algorithm issue, find the min number of coins to
change the full equal of amount money.
dp[i] = min(dp[i], dp[i-coins[j]] + 1) coins[j] is less or equal to i.

Time Complexity is: O(n)
Space Complexity is: O(n)
*/
