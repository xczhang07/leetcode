class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        if(prices.size() == 0)
           return max_profit;
        int i = 0;
        for(i = 0; i < prices.size()-1; ++i)
        {
            if(prices[i+1] - prices[i] > 0)
                max_profit += (prices[i+1] - prices[i]);
        }
        return max_profit;
    }
};

Conclusion:
an easy algorithm issue, greedy algorithm.
Time Complexity: O(n)
Space Complexity: O(1)
