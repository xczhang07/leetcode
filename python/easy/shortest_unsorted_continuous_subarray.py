class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return 0;
        sorted_array = sorted(nums)
        if nums == sorted_array:
            return 0
        i = min(i for i in range(len(nums)) if nums[i] != sorted_array[i])
        j = max(i for i in range(len(nums)) if nums[i] != sorted_array[i])
        return j-i+1
        
