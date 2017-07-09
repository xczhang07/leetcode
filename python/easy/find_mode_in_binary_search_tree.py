# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        counter = collections.Counter()
        
        def dfs(root):
            if not root:
                return
            counter[root.val] += 1
            dfs(root.left)
            dfs(root.right)
        if not root:
            return []
        dfs(root)
        max_cnt = max(counter.itervalues())
        return [k for k, v in counter.iteritems() if v == max_cnt]
        
Conclusion: usage case of inner function and collections.Counter() class
