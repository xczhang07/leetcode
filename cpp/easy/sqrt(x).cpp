class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)
            return x;
        int start = 0;
        int end = x;
        while(start <= end)
        {
            long mid = start + (end-start)/2;
            if(mid*mid == x)
                return mid;
            else if(mid*mid < x)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return end;
    }
};

Conclusion:
an easy algorithm issue, use binary search to solve this issue.
we need to take care of the exist conditional of the while loop:
when the program exit the while loop, it should be start > end, in this case, start*start > x; thus, we need to return end in this case

Time Complexity: O(logn)
Space Complexity: O(1)
