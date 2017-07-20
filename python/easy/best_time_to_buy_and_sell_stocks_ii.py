class Solution(object):
    import sys
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) <= 1:
            return 0;
        min_price = sys.maxint
        max_profit = 0
        for i in xrange(0, len(prices)-1):
            if prices[i+1] - prices[i] > 0:
                max_profit += (prices[i+1] - prices[i])
        return max_profit
