class Solution {
public:
    int findComplement(int num) {
        if(num <= 0)
            return -1;
        bool flag = false;
        for(int i = 31; i>=0; --i)
        {
            int mask = 1<<i;
            if(!flag)
            {
                if(mask & num)
                    flag = true;
            }
            if(flag)
                num = num ^ mask;
        }
        return num;
    }
};

Conclustion:
we can use xor to flip a bit of number. eg:
1 ^ 1 = 0
0 ^ 0 = 0
1 ^ 0 = 1
0 ^ 1 = 1

therefore, a number no matter is 0 or 1, if it xor with 1, the value is flip, a number no matter is 0 and 1, if it xor with 0, it will 
keep the same value. file a specific bit of the number: (num ^ (1 << i))
