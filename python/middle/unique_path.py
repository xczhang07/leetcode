class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m == 0 or n == 0:
            return 0;
        matrix = [[0]*n for i in xrange(m)]
        for i in xrange(0,m):
            matrix[i][0] = 1
        for i in xrange(0, n):
            matrix[0][i] = 1
        for i in xrange(1, m):
            for j in xrange(1, n):
                matrix[i][j] = matrix[i-1][j]+matrix[i][j-1]
        return matrix[m-1][n-1]
        
