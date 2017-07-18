class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return -1
        ret = nums[0]
        count = 1
        for i in xrange(1, len(nums)):
            if(ret == nums[i]):
                count += 1
            else:
                count -= 1
                if count == 0:
                    ret = nums[i]
                    count = 1
        return ret
