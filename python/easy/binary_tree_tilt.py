# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.tilt = 0
        
        def dfs_postorder(root):
            if not root:
                return 0
            left_sum = dfs_postorder(root.left)
            right_sum = dfs_postorder(root.right)
            self.tilt += abs(left_sum - right_sum)
            return left_sum + right_sum + root.val
        dfs_postorder(root)
        return self.tilt
