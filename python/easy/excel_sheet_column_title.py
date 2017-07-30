class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        template = "ZABCDEFGHIJKLMNOPQRSTUVWXY"
        ret = ""
        while n > 0:
            idx = n % 26
            ret = template[idx] + ret
            n = (n-1)/26
        return ret
        
