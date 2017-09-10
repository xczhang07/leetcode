# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.path_sum = 0
        
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        path = ""
        self.getSum(root, path)
        return self.path_sum
    
    def getSum(self, root, path):
        if not root:
            return
        path += str(root.val)
        if root.left is None and root.right is None:
            self.path_sum += int(path)
        self.getSum(root.left, path)
        self.getSum(root.right, path)
        return
