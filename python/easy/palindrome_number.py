class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        x = str(x)
        reverse_x = x[::-1] # pythonic way
        return x == reverse_x
