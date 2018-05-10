// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        while(start < end)
        {
            int mid = start + (end - start)/2;
            int correct = guess(mid);
            if(correct == 0)
                return mid;
            else if(correct == 1)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return end;
    }
};


Analysis: typical binary search algorithm issue.

Time Complexity: O(logN)
Space Complexity: O(1)
