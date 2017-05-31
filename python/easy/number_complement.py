class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        return num^((1<<(num.bit_length()))-1)
