class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int i = 0;
        int j = matrix[0].size()-1;
        while(i < matrix.size() && j >= 0)
        {
            if(matrix[i][j] == target)
                return true;
            else if(target > matrix[i][j])
                ++i;
            else
                --j;
        }
        return false;
    }
};


Conclusion:
比较简单的一道问题，定位在右上角的元素，如果target > matrix[i][j] => ++i; 如果 target < matrix[i][j] => --j;

Time Complexity: O(logn)
Space Complexity: O(1)

Another solution:
class Solution {
public:
    /*
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int start = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int end = row*col - 1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int number = matrix[mid/col][mid%col];
            if(number == target)
                return true;
            else if(number > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
};


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
Conclusion:
run binary search on row and column properly. 
Time Complexity: O(logM+logN)
Space Complexity: O(1)
*/
