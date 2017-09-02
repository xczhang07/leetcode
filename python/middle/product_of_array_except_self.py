class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = []
        if len(nums) == 0 or len(nums) == 1:
            return ret
        n = len(nums)
        left = [0] * n
        right = [0] * n
        left[0] = 1
        right[len(nums)-1] = 1
        product = 1
        for i in xrange(1, len(nums)):
            product = product * nums[i-1]
            left[i] = product
        product = 1
        for i in xrange(len(nums)-2, -1, -1):
            product = product * nums[i+1]
            right[i] = product
        for i in xrange(0, len(nums)):
            ret.append(left[i] * right[i])
        return ret
        
