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
