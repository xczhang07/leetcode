class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int n = M.size();
        int m = M[0].size();
        vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1},{1,-1},{-1,1},{1,1},{-1,-1}}; //direction matrix to caculate the 8 sides directions
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int cnt = 1;
                int sum = M[i][j];
                for(int k = 0; k < direction.size(); ++k)
                {
                    int x = i + direction[k][0];
                    int y = j + direction[k][1];
                    if(x < 0 || x > n-1 || y < 0 || y > m-1) //check whether or not the index is overflow
                        continue;
                    sum += (M[x][y] & 0xFF); 
                    cnt++;
                }
                M[i][j] = M[i][j] | ((sum/cnt) << 8); //store the sum result in the 8->16 bits because of the input number is only 0 -> 8 bits.
            }
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
                M[i][j] = M[i][j] >> 8; // right shift 8 bits of the results, then get the correct number
        }
        return M;
    }
};

Conclusion:
an easy level algorithm issue, but I like this one. There are several key points place I need to learn from:
1. direction matrix, using the direction matrix to caculate the index of the 8 elements around one element.
2. because it reports that the input number is from 0~255, only 8 bits number, therefore, we can use 9~16 bits to store the result.
finally, make the right shift 8 bits, then we get the result.

Time Complexity: O(m*n)
Space Complexity: O(1)
