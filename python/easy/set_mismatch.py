class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = []
        d1 = {}
        n = len(nums)
        for num in nums:
            if not num in d1:
                d1[num] = 1
            else:
                ret.append(num)
        for i in xrange(1, n+1):
            if not i in d1:
                ret.append(i)
        return ret
