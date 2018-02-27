class Solution {
public:
    string toHex(int num) {
        int count = 0;
        if(!num)
            return "0";
        string ret;
        while(num && count < 8)
        {
            int tmp = num & 15;
            if(tmp < 10)
                ret.push_back(tmp+'0');
            else
                ret.push_back('a'+tmp-10);
            num >>= 4;
            ++count;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

Conclusion:
an easy algorithm issue, but we need to know the rule to convert base10 integer to hex number.
1. we use int tmp = num & 15 (15 binary version is: 1111) to get four digits per time.
2. if the tmp is smaller than 10, we just convert it from integer to string with formula: tmp + '0', and push to the ret string back.
3. if the tmp is larger than 10, we need to convert it from 10base interger to hex with the forula: 'a' + tmp-10, and push it to the string back.
4. because the input number is a 32 bit integer, thus, we need to do it less than 8 times.
5. finally, reverse the result string and return it.

 
