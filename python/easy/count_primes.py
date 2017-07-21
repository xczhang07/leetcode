class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        import math
        if n <= 1:
            return 0
        primes = [True]*n
        j = 0
        for i in xrange(2, int(math.sqrt(n))+1):
            j = i * 2
            while j  < n:
                primes[j] = False
                j += i
        return primes.count(True)-2
        
