class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        import sys
        if len(prices) == 0:
            return 0
        max_profit = 0
        min_price = sys.maxint
        for price in prices:
            if price < min_price:
                min_price = price
            max_profit = max(max_profit, price-min_price)
        return max_profit
        
