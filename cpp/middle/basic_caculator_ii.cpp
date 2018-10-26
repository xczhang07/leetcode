class Solution {
public:
    int calculate(string s) {
        int num = 0;
        int curRes = 0;
        int res = 0;
        char prev_op = '+';
        int n = s.size();
        for(int i = 0; i < n; ++i)
        {
            char e = s[i];
            if(e >= '0' && e <= '9')
                num = num * 10 + e - '0';
            if(e == '+' || e == '-' || e == '*' || e == '/' || i == n-1)
            {
                switch(prev_op)
                {
                    case '+':
                        curRes += num;
                        break;
                    case '-':
                        curRes -= num;
                        break;
                    case '*':
                        curRes *= num;
                        break;
                    case '/':
                        curRes /= num;
                        break;
                }
                if(e == '+' || e == '-' || i == n-1)
                {
                    res += curRes;
                    curRes = 0;
                }
                prev_op = e;
                num = 0;
            }
        }
        return res;
    }
};


/*
a middle level algorithm issue.
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
