# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import sys
class Solution(object):
    ret = -sys.maxint-1
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(root):
            if not root:
                return 0
            left_h = dfs(root.left)
            right_h = dfs(root.right)
            self.ret = max(self.ret, left_h+right_h)
            return max(left_h, right_h)+1
        
        if not root:
            return 0
        dfs(root)
        return self.ret
