Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.

class Solution {
public:
    int calculate(string s) {
       if(s.size() == 0)
           return 0;
        return parseExp(s);
    }
    
    int parseExp(string& s)
    {
        int idx = 0;
        char op = '+';
        vector<int> sums;
        long num = 0;
        long ret = 0;
        while(idx < s.size())
        {
            if(s[idx] == ' ')
            {
                ++idx;
                continue;
            }
            
            if(isdigit(s[idx]))
            {
                num = 0;
                while(idx < s.size() && isdigit(s[idx]))
                {
                    num = num * 10 + s[idx]-'0';
                    ++idx;
                }
            }
            
            if(op == '+')
                sums.push_back(num);
            else if(op == '-')
                sums.push_back(-num);
            else if(op == '*')
                sums.back() *= num;
            else if(op == '/')
                sums.back() /= num;
            op = s[idx];
            ++idx;
        }
        
        for(int n : sums)
            ret += n;
        return ret;
    }
};

