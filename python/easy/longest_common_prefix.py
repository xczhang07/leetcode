class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        prefix = str()
        compare = str()
        if(len(strs) == 0):
            return prefix
        elif(len(strs) == 1):
            return strs[0]
        prefix = strs[0]
        j = 0
        for i in xrange(1, len(strs)):
            j = 0
            while(j < len(prefix) and j < len(strs[i])):
                if(prefix[j] == strs[i][j]):
                    compare += strs[i][j]
                else:
                    break
                j += 1
            prefix = compare
            compare = ""
        return prefix

# pythonic way
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        for idx, chars in enumerate(zip(*strs)):
            if len(set(chars)) > 1:
                return strs[0][:idx]
        return min(strs, key=len)
        
