# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        return self.construct(nums, 0, len(nums)-1)
    
    def construct(self, nums, start, end):
        if(start > end or start >= len(nums) or end < 0):
            return None
        m = start
        for i in xrange(start, end+1):
            if nums[i] > nums[m]:
                m = i
        root = TreeNode(nums[m])
        root.left = self.construct(nums, start, m-1)
        root.right = self.construct(nums, m+1, end)
        return root
