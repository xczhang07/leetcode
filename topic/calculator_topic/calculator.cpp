/*
In leetcode, we have 4 calculator issues, calculator, calculator ii, calculator iii and calculator iv.
for the first three, we can use a generic solution to work them out.
https://leetcode.com/problems/basic-calculator/description/
https://leetcode.com/problems/basic-calculator-ii/description/
https://leetcode.com/problems/basic-calculator-iii/description/

calculator i contains: digit, +, -, and ().
calculator ii contains: digit, +, -, *, / .
calculator iii contains: digit, +, -, *, /, and (). 

when the expresstion contains (), we can use recursive to address this easy easily.

*/
Calculator i:

class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0)
            return 0;
        int currRes = 0, res = 0, n = s.size(), num = 0;
        char op = '+';
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] >= '0' && s[i] <= '9')
                num = num * 10 + (s[i]-'0');
            if(s[i] == '(')
            {
                int j = i;
                int cnt = 0;
                for(i; i < n; ++i)
                {
                    if(s[i] == '(')
                        cnt++;
                    if(s[i] == ')')
                        cnt--;
                    if(cnt == 0)
                        break;
                }
                num = calculate(s.substr(j+1, i-j-1));
            }
            if(s[i] == '+' || s[i] == '-' || i == n-1)
            {
                switch(op)
                {
                    case '+': currRes += num; break;
                    case '-': currRes -= num; break;
                }
                res += currRes;
                num = 0;
                currRes = 0;
                op = s[i];
            }
        }
        return res;
    }
};

calculator ii solution:
class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0)
            return 0;
        int n = s.size(), currRes = 0, res = 0, num = 0;
        char op = '+';
        for(int i = 0; i < n; ++i)
        {
            if(s[i] >= '0' && s[i] <= '9')
                num = num * 10 + (s[i]-'0');
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == n-1)
            {
                switch(op)
                {
                    case '+': currRes += num; break;
                    case '-': currRes -= num; break;
                    case '*': currRes *= num; break;
                    case '/': currRes /= num; break;
                }
                if(s[i] == '+' || s[i] == '-' || i == n-1)
                {
                    res += currRes;
                    currRes = 0;
                }
                num = 0;
                op = s[i];
            }
        }
        return res;
    }
};

calculator iii solution:

class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0) return 0;
        char op = '+';
        int n = s.size(), num = 0, currRes = 0, res = 0;
        for(int i = 0; i < n; ++i)
        {
            char c = s[i];
            if(c >= '0' && c <= '9')
                num = num*10 + c-'0';
            else if(c == '(')
            {
                int j = i;
                int cnt = 0;
                for(; i < n; ++i)
                {
                    if(s[i] == '(') cnt++;
                    if(s[i] == ')') cnt--;
                    if(cnt == 0) break;
                }
                num = calculate(s.substr(j+1, i-j-1));
            }
            if(c == '+' || c == '-' || c == '*' || c == '/' || i == n-1)
            {
                switch(op)
                {
                    case '+' : currRes += num; break;
                    case '-' : currRes -= num; break;
                    case '*' : currRes *= num; break;
                    case '/' : currRes /= num; break;
                }
                if(c == '+' || c == '-' || i == n-1)
                {
                    res += currRes;
                    currRes = 0;
                }
                op = c;
                num = 0;
            }
            else
                continue;
        }
        return res;
    }
    
};
