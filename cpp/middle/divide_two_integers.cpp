class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;
        long long m = abs((long long) dividend);
        long long n = abs((long long) divisor);
        long long ret = 0;
        long long p = 0;
        while(m >= n)
        {
            long long t = n;
            p = 1;
            while(m >= t<<1)
            {
                t <<= 1;
                p <<= 1;
            }
            ret += p;
            m -= t;
        }
        cout<<dividend<<endl;
        cout<<divisor<<endl;
        if((dividend < 0 && divisor > 0)||(dividend > 0 && divisor < 0))
            ret = -ret;
        if(ret > INT_MAX || ret < INT_MIN)
            ret = INT_MAX;
        return ret;
    }
};


/*
an middle level algorithm issue on leetcode.
Time Complexity is: O(logN)
Space Complexity is: O(1)
*/
