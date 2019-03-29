Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . 
The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
 

Note: Do not use the eval built-in library function.


class Solution {
public:
    int parseExp(string& s, int& idx)
    {
        if(idx >= s.size())
            return 0;
        vector<long> sums;
        long num = 0;
        char op = '+';
        
        while(idx < s.size() && op != ')')
        {
            num = 0;
            if(s[idx] == ' ')
            {
                idx++;
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
        
        long ret = 0;
        for(int s : sums)
            ret += s;
        return ret;
    }
    
    
    int calculate(string s) {
        if(s.size() == 0)
            return 0;
        int idx = 0;
        return parseExp(s, idx);
    }
   
  
};
