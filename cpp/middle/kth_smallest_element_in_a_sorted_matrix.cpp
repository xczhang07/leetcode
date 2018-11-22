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

/*
Time Complexity is: O(nlogX), x is the diff between min_value and max_value.
Space Complexity is: O(1)
*/
