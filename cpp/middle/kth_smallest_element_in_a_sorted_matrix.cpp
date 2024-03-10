class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = matrix[0][0];
        int right = matrix[m-1][n-1];
        while(left < right)
        {
            int mid = left + (right - left)/2;
            int cnt = search_equal_less(matrix, mid);
            if(cnt < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    
    int search_equal_less(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m-1;
        int j = 0;
        int ret = 0;
        while(i >= 0 && j < n)
        {
            if(matrix[i][j] <= target)
            {
                ret += (i+1);
                ++j;
            }
            else
                --i;
        }
        return ret;
    }
};



Another similar solution with more clearly explanation.
/*
Time Complexity is: O(nlogX), x is the diff between min_value and max_value.
Space Complexity is: O(1)
*/

class Solution {
public:
    // Time Complexity is: O((n+n) * log(high - low))
    // Space Complexity is: O(1)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        int kth_val = 0;
        while(low <= high) {
            int mid = low + (high-low) / 2; // kth_value candidate.
            int cnt = getEqualOrLessThanMid(matrix, mid, n);
            if(cnt >= k) {
                kth_val = mid; // reserve the candidate.
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return kth_val;
    }
    
    int getEqualOrLessThanMid(vector<vector<int>>& matrix, int& mid, int& n) {
        int i = n - 1;
        int j = 0;
        int cnt = 0;
        while(i >= 0 && j < n) {
            if(matrix[i][j] <= mid) {
                cnt += i+1;
                ++j;
            } else {
                --i;
            }
        }
        return cnt;
    }
};

Reference video : https://www.youtube.com/watch?v=0jRTsLB8W_M
