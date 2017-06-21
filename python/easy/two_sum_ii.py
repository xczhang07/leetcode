class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        ret = []
        if len(numbers) == 0:
            return ret
        start = 0
        end = len(numbers)-1
        while start < end:
            sum = numbers[start] + numbers[end]
            if sum == target:
                ret.append(start+1)
                ret.append(end+1)
                return ret
            elif sum < target:
                start += 1
            else:
                end -= 1
