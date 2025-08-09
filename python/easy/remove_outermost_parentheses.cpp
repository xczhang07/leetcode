class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ret, balance = [], 0
        for c in s:
            if c == '(' and balance > 0:
                ret.append(c)
            if c == ')' and balance > 1:
                ret.append(c)
            balance += 1 if c == '(' else -1
        return "".join(ret)
