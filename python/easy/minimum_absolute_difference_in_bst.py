# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ret = sys.maxint
        self.pre = -1
        
        def dfs_inorder(root):
            if not root:
                return
            dfs_inorder(root.left)
            if self.pre != -1:
                self.ret = min(self.ret, root.val-self.pre)
            self.pre = root.val
            dfs_inorder(root.right)
        
        dfs_inorder(root)
        return self.ret

Conclustion:
Python does not have reference concept; thus, we use class variable as reference to keep track of the recursive.
