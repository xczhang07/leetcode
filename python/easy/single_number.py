class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = 0
        for ele in nums:
            ret = ret ^ ele
        return ret
        
