class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = -sys.maxint - 1
        cur_sum = 0
        for num in nums:
            cur_sum = max(cur_sum+num, num)
            ret = max(ret, cur_sum)
        return ret
            
