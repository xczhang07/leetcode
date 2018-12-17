class Solution {
public:
    string addBinary(string a, string b) {
        /* corner case check */
        if(a.size() == 0)
            return b;
        if(b.size() == 0)
            return a;
        int carry = 0;
        string ret;
        int i = a.size()-1;
        int j = b.size()-1;
        int num1 = 0;
        int num2 = 0;
        int sum = 0;
        while(i >= 0 && j >= 0)
        {
            num1 = a[i] - '0';
            num2 = b[j] - '0';
            sum = num1 + num2 + carry;
            carry = sum / 2;
            sum = sum % 2;
            ret.insert(ret.begin(), sum+'0');
            --i;
            --j;
        }
        while(i >= 0)
        {
            num1 = a[i] - '0';
            sum = num1 + carry;
            carry = sum / 2;
            sum = sum % 2;
            ret.insert(ret.begin(), sum+'0');
            --i;
        }
        while(j >= 0)
        {
            num2 = b[j] - '0';
            sum = num2 + carry;
            carry = sum/2;
            sum = sum%2;
            ret.insert(ret.begin(), sum+'0');
            --j;
        }
        if(carry)
            ret.insert(ret.begin(), carry+'0');
        return ret;
    }
};


Conclusion: an easy algorithm issue on leetcode, do not have too much comments on it. 
just be careful on the following tips: 
1. convert char to int: integer = charactor - '0'
2. convert int to char: charactor = integer + '0'
3. don't forget add the carry number.
    
 Solution 2
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() == 0) return b;
        if(b.size() == 0) return a;
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        string ret;
       while(i >= 0 || j >= 0 || carry > 0)
       {
           int num1 = i >= 0 ? (a[i]-'0') : 0;
           int num2 = j >= 0 ? (b[j]-'0') : 0;
           int sum = num1 + num2 + carry;
           carry = sum/2;
           sum %= 2;
           char c = sum+'0';
           ret.insert(ret.begin(), c);
           --i;
           --j;
       }
        return ret;
        
    }
};
