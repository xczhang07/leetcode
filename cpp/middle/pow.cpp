class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        bool positive = true;
        if(n < 0)   positive = false;
        ret = power(x, n);
        if(!positive)
            return 1/power(x,n);
        else
            return power(x,n); 
    }
    
    double power(double x, int n)
    {
        if(n == 0)
            return 1;
        double half = power(x , n/2);
        if(n%2 == 0)
            return half*half;
        else
            return half*half*x;
    }
};

//recursive

double myPow(double x, int n) {
        double ret = 1;
        bool flag = false;
        if(n < 0)
            flag = true;
        n = abs(n);
        while(n)
        {
            if(n%2)
                ret *= x;
            n/=2;
            x*=x;
        }
        if(flag)
            return 1/ret;
        else
            return ret;
    }

// iteration

Conclusion: a middle level leetcode algorithm, not hard, we can use both recursive and iteration to resolve this issue.

Time Complexity: O(logn)
Space Complexity: O(1)
