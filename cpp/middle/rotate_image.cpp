class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return;
        vector<int> tmp;
        for(int i = 0; i < n-1; ++i)
        {
            for(int j = 0; j < n-i; ++j)
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
        }
        for(int i = 0; i < n/2; ++i)
        {
            tmp = matrix[i];
            matrix[i] = matrix[n-1-i];
            matrix[n-1-i] = tmp;
        }
        return;
    }
};


Conclusion:
basic operation for matrix. 
1. 先反转对角线的元素。
2. 再相对于横轴中间轴进行反转。

note: 如果一个元素的坐标是:[i,j], 齐对角线坐标就是[n-1-j,n-1-i]

Time Complexity: O(n^2)
Space Complexity: O(n)


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) {
            return;
        }
        int n = matrix.size();
        int l = 0, r = n-1;
        while(l < r) {
            int top = l;
            int bottom = r;
            for(int i = 0; i < r-l; ++i) {
                int topLeft = matrix[top][l+i];
                // move bottomLeft val to topLeft.
                matrix[top][l+i] = matrix[bottom-i][l];
                // move bottomRight val to bottomLeft.
                matrix[bottom-i][l] = matrix[bottom][r-i];
                // move topRight val to bottomRight.
                matrix[bottom][r-i] = matrix[top+i][r];
                // move topLeft val to topRight.
                matrix[top+i][r] = topLeft;
            }
            l += 1;
            r -= 1;
        }
        return;
    }
};
Reference: https://www.youtube.com/watch?v=fMSJSS7eO1w
