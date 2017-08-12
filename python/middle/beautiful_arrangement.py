class Solution(object):
    cnt = 0
    
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        visited = [False]*(N+1)
        pos = 1
        self.helper(visited, pos, N)
        return self.cnt
    
    def helper(self, visited, pos, n):
        if(pos > n):
            self.cnt += 1
            return
        for i in xrange(1, n+1):
            if not visited[i]:
                if i%pos == 0 or pos%i == 0:
                    visited[i] = True
                    self.helper(visited, pos+1, n)
                    visited[i] = False
        return
            
        
