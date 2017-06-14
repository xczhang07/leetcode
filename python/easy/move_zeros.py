class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if len(nums) <= 1:
            return
        index = 0
        travel = 0
        while(travel < len(nums)):
            if nums[travel] != 0 :
                tmp = nums[index]
                nums[index] = nums[travel]
                nums[travel] = tmp
                index = index+1
            travel = travel+1
        
        
