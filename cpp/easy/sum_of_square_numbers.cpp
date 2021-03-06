class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 0)
            return false;
        int start = 0;
        int end = sqrt(c);
        while(start <= end)
        {
            if(start*start + end*end == c)
                return true;
            else if(start*start + end*end > c)
                --end;
            else
                ++start;
        }
        return false;
    }
};


Conclusion:
Easy algorithm issue
Time complexity is: O(sqrt(n))
Space complexity is: O(1)


