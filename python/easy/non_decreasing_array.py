class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) <= 1:
            return True
        cnt = 0
        for i in xrange(0, len(nums)-1):
            if nums[i] > nums[i+1]:
                if i == 0 or nums[i-1] <= nums[i+1]:
                    nums[i] = nums[i+1]
                else:
                    nums[i+1] = nums[i]
                cnt += 1
                if cnt == 2:
                    return False
        return True
