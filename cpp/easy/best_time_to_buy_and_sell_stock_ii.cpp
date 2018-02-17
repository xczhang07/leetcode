class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        if(prices.size() <= 1)
            return maxProfit;
        for(int i = 0; i < prices.size()-1; ++i)
        {
            if(prices[i+1] > prices[i])
                maxProfit += (prices[i+1] - prices[i]);
        }
        return maxProfit;
    }
};


Conclusion:
an easy algorithm issue, greedy algorithm.

Time Complexity: O(n)
Space Complexity: O(1)
