class Solution {
public:
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int r = 0;
        int c = matrix[0].size()-1;
        while(r < matrix.size() && c >= 0)
        {
            if(matrix[r][c] == target)
                return true;
            else if(matrix[r][c] < target)
                r++;
            else
                c--;
        }
        return false;
    }
};

/*
Conclusion:
Time Complexity : O(m+n)
Space Complexity : O(1)
*/

class Solution {
public:

    bool binarySearch(vector<int>& arr, int& target) {
        int left = 0;
        int right = arr.size() - 1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(target == arr[mid]) {
                return true;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int r = matrix.size();
        int c = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[r-1][c-1]) {
            return false;
        }
        int h = matrix[0].size();
        for(int i = 0; i < matrix.size(); ++i) {
            if(target < matrix[i][0] || target > matrix[i][h-1]) {
                continue;
            } else {
                if(binarySearch(matrix[i], target)) {
                    return true;
                }
            }
        }
        return false;
    }
};
