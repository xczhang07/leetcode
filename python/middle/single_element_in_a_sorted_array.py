class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        right = len(nums)-1
        while left < right:
            mid = left + (right-left)/2
            if mid%2 == 0:
                if nums[mid] == nums[mid+1]:
                    left = mid+2
                elif nums[mid] == nums[mid-1]:
                    right = mid-2
                else:
                    return nums[mid]
            else:
                if nums[mid] == nums[mid+1]:
                    right = mid-1
                elif nums[mid] == nums[mid-1]:
                    left = mid+1
                else:
                    return nums[mid]
        return nums[left]
        
