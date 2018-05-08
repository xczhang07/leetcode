class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0)
            return false;
        else if(num == 1)
            return true;
        else
        {
            while(num!=1)
            {
                if(num % 4 != 0)
                    return false;
                num = num/4;
            }
        }
        return num==1;
    }
};


Conclusion: an easy algorithm issue, to check a number whether or not is power of 4, which is very similiar with
power of two and power of three.
