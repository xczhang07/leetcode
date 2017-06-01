class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        stack = list()
        d1 = dict()
        for num in nums:
            while stack and stack[-1] < num:
                d1[stack.pop()] = num
            stack.append(num)
        return [d1.get(n, -1) for n in findNums]
        
Conclustion:
Using a stack to maintain and caculate the next greater element 
