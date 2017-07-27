class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        import collections
        if len(nums) <= 1:
            return 0
        ret = 0
        counter = collections.Counter(nums)
        for x in counter:
            if x+1 in counter:
                ret = max(ret, counter[x]+counter[x+1])
        return ret
    
        
