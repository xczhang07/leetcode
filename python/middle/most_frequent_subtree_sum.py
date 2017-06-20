# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import sys

class Solution(object):
    
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def getSum(node):
            if node == None:
                return 0
            sum = node.val + getSum(node.left) + getSum(node.right)
            if sum in d:
                d[sum] += 1
            else:
                d[sum] = 1
            return sum

        if root == None:
            return []
        d = dict()
        getSum(root)
        max_count = max(d.values())
        return [s for s in d.keys() if d[s] == max_count]
