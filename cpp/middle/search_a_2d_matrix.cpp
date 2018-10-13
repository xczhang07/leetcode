class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int r = matrix.size();
        int c = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[r-1][c-1])
            return false;
        int left = 0;
        int right = r-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        int e = right;
        left = 0;
        right = c - 1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(matrix[e][mid] == target)
                return true;
            else if(matrix[e][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};


/*
Conclusion: an middle level algorithm issue, binary search.
Time Complexity O(logN)
Space Complexity O(1)
*/
