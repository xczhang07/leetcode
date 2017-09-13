class Solution(object):
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        cnt = 1
        ret = 1
        for i in xrange(1, len(nums)):
            if nums[i-1] < nums[i]:
                cnt += 1
                ret = max(ret, cnt)
            else:
                cnt = 1
        return ret
