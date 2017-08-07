# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    most_left_val = 1
    max_depth = 1
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if(root == None):
            return 0
        depth = 1
        self.most_left_val = root.val
        def dfs(root, level):
            if(not root):
                return
            if(level > self.max_depth):
                self.most_left_val = root.val
                self.max_depth = level
            dfs(root.left, level+1)
            dfs(root.right, level+1)
        dfs(root, depth)
        return self.most_left_val
        
