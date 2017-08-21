class Solution(object):
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0 or len(nums) == 1:
            return 0
        start = 0
        end = len(nums)-1
        ret = 0
        nums.sort()
        while start < end:
            ret += (nums[end]-nums[start])
            start += 1
            end -= 1
        return ret
        
