class Solution {
public:
    string convertToBase7(int num) {
        int ret = 0;
        int times = 0;
        while(num)
        {
            int reminder = num % 7;
            ret += reminder * pow(10, times);
            num /= 7;
            times++;
        }
        return to_string(ret);
    }
};

Conclusion:
an easy algorithm issue, just need to know:
1. the rule how to convert decimal number to the other based number.
2. know how to use pow() function of c++

