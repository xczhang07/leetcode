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
