class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 0)
            return false;
        int start = 0;
        int end = num;
        while(start <= end)
        {
            long mid = start + (end-start)/2;
            long product = mid * mid;
            if(product == num)
                return true;
            else if(product < num)
                start = mid + 1;
            else
                end = mid-1;
        }
        return false;
    }
};


Conclusion:
Easy, Binary search, time complexity is: O(logN)
