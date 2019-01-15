class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0)
            return 0;
        int n = s.size(), num = 0, currRes = 0, res = 0;
        char op = '+';
        for(int i = 0; i < n; ++i)
        {
            if(s[i] >= '0' && s[i] <= '9')
                num = num*10 + s[i]-'0';
            else if(s[i] == '(')
            {
                int j = i;
                int cnt = 0;
                for(; i < n; ++i)
                {
                    if(s[i] == '(') cnt++;
                    else if(s[i] == ')') cnt--;
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
                currRes = 0;
                op = s[i];
                num = 0;
            }
        }
        return res;
    }
};

Time Complexity is: O(n^2)
Space Complexity is: O(n)
    
Solution 2:
class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0)
            return 0;
        int i = 0;
        return parseExp(s, i);
    }
    
    int parseExp(string& s, int& i)
    {
        char op = '+';
        int ret = 0;
        int num = 0;
        while(i < s.size() && op != ')')
        {
            num = 0;
            if(s[i] == ' ')
            {
                ++i;
                continue;
            }
            else if(isdigit(s[i]))
            {
                while(i < s.size() && isdigit(s[i]))
                {
                    num = num * 10 + (s[i]-'0');
                    ++i;
                }
            }
            else if(s[i] == '(')
            {
                ++i;
                num = parseExp(s, i);
            }
            if(op == '+')
                ret += num;
            else if(op == '-')
                ret -= num;
            op = s[i];
            ++i;
        }
        return ret;
    }
};

Time Complexity is: O(n)
Space Complexity is: O(n)
