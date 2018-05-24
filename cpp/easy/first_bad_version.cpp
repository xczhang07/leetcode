// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 0)
            return 0;
        int left = 0;
        int right = n;
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};


Conclusion: an easy algorithm issue, we can using binary search to work it out.

Time Complexity: O(lgN)
Space Complexity: O(1)

