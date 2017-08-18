class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = [0]*2
        xor_val = 0
        for num in nums:
            xor_val ^= num
        first_one = xor_val & (~(xor_val-1))
        for num in nums:
            if ((num & first_one) != 0):
                ret[0] ^= num
            else:
                ret[1] ^= num
        return ret
