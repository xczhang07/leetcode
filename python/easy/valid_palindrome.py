class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) <= 1:
            return True
        right = 0
        left = len(s)-1
        while(right < left):
            while right < left and not s[right].isalnum():
                right += 1
            while right < left and not s[left].isalnum():
                left -= 1
            if s[right].lower() == s[left].lower():
                right += 1
                left -= 1
            else:
                return False
        return True
        
Conclusion:
python has function which name is: isalnum(), we need to take care of this function, new function for studying

# 2025/07/25
The above solution is not concise pythonic
the following solution is pythonic and better

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = [c.lower() for c in s if c.isalnum()]
        return s == s[::-1]
