# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        def isSame(s, t):
            if not s and not t:
                return True
            if not s or not t:
                return False
            if s.val == t.val:
                l = isSame(s.left, t.left)
                r = isSame(s.right, t.right)
                return l and r
            else:
                return False

        if s is None and t is None:
            return True
        if s is None or t is None:
            return False
        return isSame(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)
        
        
        
