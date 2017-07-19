class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        if len(flowerbed) == 0:
            return False
        prev = 0
        post = 0
        for i in xrange(0, len(flowerbed)):
            if flowerbed[i] == 0:
                if i == len(flowerbed)-1:
                    post = 0
                else:
                    post = flowerbed[i+1]
                if i == 0:
                    prev = 0
                else:
                    prev = flowerbed[i-1]
                if prev + post == 0:
                    n -= 1
                    flowerbed[i] = 1
        if n <= 0:
            return True
        else:
            return False
        
