class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        c_idx = list()
        ret = list()
        for i, v in enumerate(S):
            if v == C:
                c_idx.append(i)

        for i, v in enumerate(S):
            distance = [abs(i-dist) for dist in c_idx]
            ret.append(min(distance))
        return ret
        



Conclusion: easy leetcode issue, iterate the given string S two times, the first time
caculate the index position where charactor C appears, the second iteration caculate the min
distance 


Time Complexity: O(n)
Space Complexity: O(n)
