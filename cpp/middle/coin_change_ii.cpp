class Solution {
public:
     int change(int amount, vector<int>& coins){
         vector<int> dp(amount+1, 0);
         dp[0] = 1;
         for(int c : coins)
         {
             for(int i = c; i <= amount; ++i)
             {
                 dp[i] += dp[i-c];
             }
         }
         return dp[amount];
    }    
};


/*
a middle level algorithm issue on leetcode, dynamic programming issue. state change function is: dp[i] += dp[i-c]
Time Complexity: O(m*n)
space complexity: O(n)
*/
