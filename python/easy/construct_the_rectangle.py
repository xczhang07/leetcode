class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        sqrt = int(math.sqrt(area))
        while area % sqrt != 0:
            sqrt -= 1
        return [area/sqrt, sqrt]
