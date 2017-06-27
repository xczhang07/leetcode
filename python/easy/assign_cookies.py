class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        ret = 0
        if len(g) == 0 or len(s) == 0:
            return ret
        s.sort()
        g.sort()
        i = len(g) - 1
        j = len(s) - 1
        while i >= 0 and j >= 0:
            if s[j] >= g[i]:
                ret += 1
                j -= 1
            i -= 1
        return ret
        
      
Conclusion:
Greedy Algorithm
