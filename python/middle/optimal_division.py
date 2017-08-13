class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if len(nums) == 0:
            return ""
        elif len(nums) == 1:
            return str(nums[0])
        elif len(nums) == 2:
            return str(nums[0])+"/"+str(nums[1])
        ret = ""
        ret = str(nums[0])+"/("+str(nums[1])
        for i in xrange(2, len(nums)):
            ret = ret + "/" + str(nums[i])
        ret += ")"
        return ret
        
