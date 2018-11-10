class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0)
            return {{}};
        if(n == 1)
            return {{1}};
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int top = 0;
        int left = 0;
        int right = n-1;
        int bottom = n-1;
        int k = 1;
        while(true)
        {
            for(int i = left; i <= right; ++i)
            {
                ret[top][i] = k;
                ++k;
            }
            ++top;
            if(top > bottom) break;
            
            for(int i = top; i <= bottom; ++i)
            {
                ret[i][right] = k;
                ++k;
            }
            --right;
            if(left > right) break;
            
            for(int i = right; i >= left; --i)
            {
                ret[bottom][i] = k;
                ++k;
            }
            --bottom;
            if(top > bottom) break;
            
            for(int i = bottom; i >= top; --i)
            {
                ret[i][left] = k;
                ++k;
            }
            ++left;
            if(left > right) break;
        }
        return ret;
    }
};


/*
Conclusion:
a middle level algorithm issue.
Time Complexity is: O(n^2)
Space Complexity is: O(n^2)
*/
