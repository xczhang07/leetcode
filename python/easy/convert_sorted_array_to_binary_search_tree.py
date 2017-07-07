# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums) == 0:
            return None
        elif len(nums) == 1:
            return TreeNode(nums[0])
        return self.dfsPreorder(nums, 0, len(nums)-1)
    
    def dfsPreorder(self, nums, start, end):
        if start > end:
            return None
        mid = (start + end)/2
        root = TreeNode(nums[mid])
        root.left = self.dfsPreorder(nums, start, mid-1)
        root.right = self.dfsPreorder(nums, mid+1, end)
        return root
