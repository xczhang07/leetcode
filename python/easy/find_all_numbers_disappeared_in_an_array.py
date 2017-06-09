class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        map = [0 for x in range(len(nums)+1)]
        idx = 0
        ret = []
        for idx in range(0, len(nums)):
            map[nums[idx]]+=1
        idx = 0
        for idx in range(1, len(map)):
            if map[idx] == 0:
                ret.append(idx)
        return ret
