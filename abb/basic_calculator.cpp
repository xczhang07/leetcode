Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.

class Solution {
public:
    int parseExp(string& s, int& idx)
    {
        if(idx >= s.size())
            return 0;
        int sum = 0;
        long num = 0;
        char op = '+';
        
        while(idx < s.size() && op != ')')
        {
            num = 0;
            if(s[idx] == ' ')
            {
                ++idx;
                continue;
            }
            if(isdigit(s[idx]))
            {
                while(idx < s.size() && isdigit(s[idx]))
                {
                    num = num*10 + s[idx]-'0';
                    ++idx;
                }
            }
            if(s[idx] == '(')
            {
                ++idx;
                num = parseExp(s, idx);
            }
            if(op == '+')
                sum += num;
            if(op == '-')
                sum -= num;
            op = s[idx];
            ++idx;
        }
        
        return sum;
    }
    
    int calculate(string s) {
        /* time complexity is O(n) */
        if(s.size() == 0)
            return 0;
        int idx = 0;
        return parseExp(s, idx);
    }
    
    
};
