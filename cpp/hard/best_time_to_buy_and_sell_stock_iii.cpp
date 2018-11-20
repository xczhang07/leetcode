class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int n = prices.size();
        vector<int> leftProfit(n, 0);
        int min_price = prices[0];
        int maxLeftProfit = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] < min_price)
                min_price = prices[i];
            maxLeftProfit = max(maxLeftProfit, prices[i]-min_price);
            leftProfit[i] = maxLeftProfit;
        }
        
        int ret = leftProfit[n-1];
        int maxRightProfit = 0;
        int max_price = prices[n-1];
        for(int i = n-2; i >= 0; --i)
        {
            if(prices[i] > max_price)
                max_price = prices[i];
            maxRightProfit = max(maxRightProfit, max_price-prices[i]);
            ret = max(ret, maxRightProfit + leftProfit[i]);
        }
        return ret;
    }
};
