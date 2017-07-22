# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        ret = []
        if not root:
            return ret
        q = []
        count = 0
        q.append(root)
        while(len(q) != 0):
            tmpq = []
            ret.append(1.0 * sum([n.val for n in q]) / len(q))
            for n in q:
                if n.left:
                    tmpq.append(n.left)
                if n.right:
                    tmpq.append(n.right)
            q = tmpq
        return ret
        
