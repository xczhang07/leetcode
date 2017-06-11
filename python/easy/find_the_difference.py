class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if len(t) <= len(s):
            return ret
        ds = collections.Counter(s)
        dt = collections.Counter(t)
        return (dt-ds).keys().pop()
        
        
