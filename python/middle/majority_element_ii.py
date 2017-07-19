class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = []
        if len(nums) == 0:
            return ret
        num1 = 0
        num2 = 0
        num1_count = 0
        num2_count = 0
        for i in nums:
            if i == num1:
                num1_count += 1
            elif i == num2:
                num2_count += 1
            elif num1_count == 0:
                num1 = i
                num1_count = 1
            elif num2_count == 0:
                num2 = i
                num2_count = 1
            else:
                num1_count -= 1
                num2_count -= 1
        num1_count = 0
        num2_count = 0
        for j in nums:
            if num1 == j:
                num1_count += 1
            elif num2 == j:
                num2_count += 1
        if num1_count > len(nums)/3:
            ret.append(num1)
        if num2_count > len(nums)/3:
            ret.append(num2)
        return ret
        
