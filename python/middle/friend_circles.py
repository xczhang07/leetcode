
class Solution(object):
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        def dfs(idx):
            if visited[idx]:
                return False
            visited[idx] = True
            for i in xrange(0, len(M)):
                if not M[idx][i] or visited[i]:
                    continue
                if not dfs(i):
                    return False
            return True
        
        n = len(M)
        visited = [False]*n
        ret = 0
        for i in xrange(0, len(M)):
            if dfs(i):
                ret += 1
        return ret
        
        
        
