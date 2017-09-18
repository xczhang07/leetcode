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
