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

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount <= 0) {
            return 0;
        }
        sort(coins.begin(), coins.end());
        queue<int> q;
        vector<bool> visited(amount+1, 0);
        visited[amount] = true;
        q.push(amount);
        int steps = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size) {
                int money = q.front();
                q.pop();
                for(int c: coins) {
                    int rest = money-c;
                    if(rest == 0) {
                        return steps;
                    }
                    if(rest < 0) {
                        break;
                    }
                    if(!visited[rest]) {
                        visited[rest] = true;
                        q.push(rest);
                    }
                }
                size -= 1;
            }
            steps += 1;
        }
        return -1;
    }
};
