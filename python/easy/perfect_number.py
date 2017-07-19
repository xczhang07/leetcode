import math
class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num < 0:
            return False
        if num == 1:
            return False
        sum = 1
        for i in xrange(2, int(math.sqrt(num))+1):
            if (num % i == 0):
                sum += (i + num/i)
            if i * i == num:
                num -= i
            if sum > num:
                return False
        return sum == num
        
