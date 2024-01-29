class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 0)
            return false;
        long long int start = 0;
        long long int end = sqrt(c);
        while(start <= end)
        {
            long long int sum = start*start + end*end;
            if(sum == c)
                return true;
            else if(sum > c)
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


