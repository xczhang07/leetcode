class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        int left = 0;
        int right = A.size()-1;
        while(left < right)
        {
            int mid = (right - left)/2 + left;
            if(A[mid] < A[mid+1])
                left = mid;
            else if(A[mid-1] > A[mid])
                right = mid;
            else
                return mid;
        }
    }
};


Conclusion:
an easy algorithm issue on leetcode, we can use binary search to resolve this issue.
Time Complexity: O(logN)
Space Complexity: O(1)
