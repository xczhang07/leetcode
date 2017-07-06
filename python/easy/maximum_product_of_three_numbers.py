class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        n = len(nums)-1
        if nums[0] >= 0:
            return nums[n-2]*nums[n-1]*nums[n]
        else:
            return max(nums[n-2]*nums[n-1]*nums[n], nums[0]*nums[1]*nums[n])
