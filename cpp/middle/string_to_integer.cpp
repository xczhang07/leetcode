class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0)
            return 0;
        int i = 0;
        while(i < str.size() && str[i] == ' ')
            ++i;
        int flag = 1;
        if(str[i] == '-' || str[i] == '+')
        {
            if(str[i] == '-')
                flag = -1;
            ++i;
        }
        long long int base = 0;
        while(i < str.size() && (str[i] >= '0' && str[i] <= '9'))
        {
            base = base * 10 + (str[i]-'0');
            ++i;
            if(base > INT_MAX)
            {
                if(flag == -1) return INT_MIN;
                else return INT_MAX;
            }
            
        }
        return base * flag;
    }
};

/*
a middle level algorithm issue.
time complexity is: O(n)
space complexity is: O(1)
*/
