# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ret = []
        if not root:
            return ret
        q = []
        q.append(root)
        max_val = -sys.maxint - 1
        while len(q) != 0:
            n = len(q)
            max_val = -sys.maxint-1
            for i in xrange(0, n):
                tmpNode = q[0]
                q.pop(0)
                max_val = max(max_val, tmpNode.val)
                if tmpNode.left:
                    q.append(tmpNode.left)
                if tmpNode.right:
                    q.append(tmpNode.right)
            ret.append(max_val)
        return ret
