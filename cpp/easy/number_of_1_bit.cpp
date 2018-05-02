class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        int ret = 0;
        int mask = 1;
        while(n != 0)
        {
            int val = n & mask;
            if(val)
                ++ret;
            n = n >> 1;
        }
        return ret;
    }
};

Conclusion:
an easy algorithm issue, caculate the number contains how many '1's in the given integer.
