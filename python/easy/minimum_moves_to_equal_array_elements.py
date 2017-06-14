class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0 or len(nums) == 1:
            return 0
        min_val = sys.maxint
        for num in nums:
            min_val = min(min_val, num)
        ret = 0
        for num in nums:
            ret += num-min_val
        return ret
