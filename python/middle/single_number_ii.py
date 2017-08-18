class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = 0
        if len(nums) == 0:
            return ret
        bit_sum = 0
        for i in xrange(0, 32):
            bit_sum = 0
            for num in nums:
                bit_val = (num>>i) & 1
                bit_sum += bit_val
            bit_sum = bit_sum % 3
            if i == 31 and bit_sum:
                ret -= 1 << 31
            else:
                ret |= bit_sum << i
        return ret
        
        
Note:
In python, an integer is unlimit large, so we can't use the last index(i==31) 0 or 1 to judge whether or not a number is positive or negative.
thus, we need to manually adjust it.
