class Solution(object):
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return len(nums)
        max_len = 0
        for i in xrange(0, len(nums)):
            j = i
            local_len = 0;
            while nums[j] >= 0:
                local_len += 1
                idx = nums[j]
                nums[j] = -1
                j = idx
            max_len = max(max_len, local_len)
        return max_len
                
        
