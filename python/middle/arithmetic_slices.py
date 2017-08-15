class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        cnt = 0
        ret = 0
        for i in xrange(2, len(A)):
            if A[i]-A[i-1] == A[i-1]-A[i-2]:
                cnt += 1
                ret += cnt
            else:
                cnt = 0
        return ret
