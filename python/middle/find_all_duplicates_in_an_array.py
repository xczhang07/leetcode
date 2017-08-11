class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = []
        if len(nums) == 0:
            return ret
        for idx in xrange(0, len(nums)):
            index = abs(nums[idx]) - 1
            if nums[index] < 0:
                ret.append(index+1)
            else:
                nums[index] = -nums[index]
        return ret
        
