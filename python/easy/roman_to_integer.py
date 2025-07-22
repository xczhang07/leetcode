class Solution:
    def romanToInt(self, s: str) -> int:
        if len(s) == 0:
            return 0
        m = {
            "I":1,
            "V":5,
            "X":10,
            "L":50,
            "C":100,
            "D":500,
            "M":1000,
        }
        ans = 0
        for idx , val in enumerate(s):
            if idx < len(s)-1 and m[s[idx]] < m[s[idx+1]]:
                ans -= m[s[idx]]
            else:
                ans += m[s[idx]]
        return ans
