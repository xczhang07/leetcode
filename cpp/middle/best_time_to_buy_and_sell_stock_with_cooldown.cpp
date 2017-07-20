class Solution {
public:
    //  a dynamic programming algorithm question.
    //  we need to maintain two arrays, one is sell[] another is buy[]
    //  sell[i] means the maxiam profit make without holding any stocks at the ith day.
    //  buy[i]  means the maxiam profit make with purchasing stock at the ith day.
    //  thus, we have the two state transition equation as following:
    //  sell[i] = max(sell[i-1], buy[i-1]+prices[i])   this equation means the sell[i] could be two options, one is yesterday sold the stock
    //  and today, no action(cooldown), or today sell the stock today which was yesterday purchase (buy[i-1]+prices[i]). We get the maxim         //  profit either
    //  buy[i] = max(buy[i-1], sell[i-2]-prices[i]) this equation means the buy[i] could be two options as well, one is no action at today.
    //  all purchase the stock today (sell[i-2] - prices[i]), here using i-2 because of cooldown restriction.
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int n = prices.size();
        int buy[n] = {0};
        int sell[n] = {0};
        buy[0] = -prices[0]; // the first day buy[0] profit should be -prices[0]
        sell[0] = 0;  // the first day sell[0] max profit should be 0 (buy and sell at the first day, no gain)
        for(int i = 1; i < prices.size(); ++i)
        {
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
            buy[i] = max(buy[i-1], (i > 1? sell[i-2]:0) - prices[i]);  //use i-2 at here because cooldown restriction
        }
        return sell[n-1];
    }
};


Conclusion:
DP issue, which is the exactly with the issue best_time_to_buy_and_sell_stock_ii except the cooldown restriction.
Need to analyse for a while to understand.
Time Complexity:
O(n)
Space Complexity:
O(n)
