class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return ret;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int left = 0;
        int right = n-1;
        int bottom = m-1;
        while(true)
        {
                for(int i = left; i <= right; ++i)
                    ret.push_back(matrix[top][i]);
                ++top;
                if(top > bottom)
                    break;
           
                for(int i = top; i <= bottom; ++i)
                    ret.push_back(matrix[i][right]);
                --right;
                if(left > right)
                    break;
            
                for(int i = right; i >= left; --i)
                    ret.push_back(matrix[bottom][i]);
                --bottom;
                if(top > bottom)
                    break;
            
                for(int i = bottom; i >= top; --i)
                    ret.push_back(matrix[i][left]);
                ++left;
                if(left > right)
                    break;
            
        }
        return ret;
    }
};

/*
Time Complexity is: O(m*n)
Space Complexity is: O(m*n)
*/
