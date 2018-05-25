class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        while(x)
        {
            ret = ret*10 + x%10;
            x /= 10;
        }
        if(ret > INT_MAX || ret < INT_MIN)
            return 0;
        else
            return ret;
    }
};


Conclusion: an easy level algorithm issue. 

Time Complexity: O(n)
Space Complexity: O(1)
