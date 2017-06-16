class Solution(object):
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        length = len(s)
        ret = ""
        start = 0
        end = k-1
        while(1):
            if length <= k:
                ret += s[start:length][::-1]
                break
            ret += s[start:end+1][::-1]
            ret += s[end+1:end+k+1]
            if start+2*k < length-1 and end+2*k >= length-1:
                ret += s[(start+2*k):length][::-1]
                break
            elif start+2*k >= length:
                break
            else:
                start += 2*k
                end += 2*k
        return ret
