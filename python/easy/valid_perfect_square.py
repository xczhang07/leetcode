class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        start, end = 0, num
        while start <= end:
            mid = start + (end - start)/2
            product = mid * mid
            if product == num:
                return True
            elif product < num:
                start = mid + 1
            else:
                end = mid - 1
        return False
