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
