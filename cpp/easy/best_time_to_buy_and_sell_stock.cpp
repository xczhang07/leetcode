class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int min_price = INT_MAX;
        int max_profit = 0;
        for(auto price: prices)
        {
            if(price < min_price)
                min_price = price;
            max_profit = max(max_profit, price-min_price);
        }
        return max_profit;
    }
};


Conclusion:
an easy level algorithm issue.
iterate the input prices array, find out the min price, then use the current price minus min_price to find out the max_profit value.
Time Complexity: O(n)
Space Complexity: O(1)
