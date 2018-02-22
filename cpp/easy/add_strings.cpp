class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        string ret;
        int number1 = 0;
        int number2 = 0;
        int sum = 0;
        while(i >= 0 && j >= 0)
        {
            number1 = num1[i] - '0';
            number2 = num2[j] - '0';
            sum = number1 + number2 + carry;
            carry = sum / 10;
            ret = to_string(sum%10) + ret;
            --i;
            --j;
        }
        while(i >= 0)
        {
            number1 = num1[i] - '0';
            sum = number1 + carry;
            carry = sum / 10;
            ret = to_string(sum % 10) + ret;
            --i;
        }
        while(j >= 0)
        {
            number2 = num2[j] - '0';
            sum = number2 + carry;
            carry = sum / 10;
            ret = to_string(sum % 10) + ret;
            --j;
        }
        if(carry)
            ret = to_string(carry) + ret;
        return ret;
    }
};


Conclusion:
an easy algorithm issue, very easy, just need to remember convert char to int formula is: int number = num[i] - '0';

Time Complexity: O(n)
Space Complexity: O(1)
