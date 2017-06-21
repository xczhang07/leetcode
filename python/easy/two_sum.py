class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ret = []
        if len(nums) == 0:
            return ret
        d = {}
        idx = 0
        for idx in xrange(0, len(nums)):
            rest = target - nums[idx]
            if rest in d:
                ret.append(idx)
                ret.append(d[rest])
                return ret
            d[nums[idx]] = idx
        
