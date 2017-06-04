class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        cnt = 0
        max_len = 0
        for num in nums:
            if num == 1:
                cnt += 1
            if num == 0:
                max_len = max(cnt, max_len)
                cnt = 0
        max_len = max(cnt, max_len)
        return max_len
