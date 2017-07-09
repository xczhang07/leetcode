class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        start, end = 0, len(nums)-1
        while start <= end:
            mid = start + (end - start)/2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                start = mid + 1
                if start >= len(nums):
                    return len(nums)
                else:
                    if nums[start] > target:
                        return start
            else:
                end = mid - 1
                if end < 0:
                    return 0
                else:
                    if nums[end] < target:
                        return end+1
