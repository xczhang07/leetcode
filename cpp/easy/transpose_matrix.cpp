class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> ret(n, vector<int>(m, 0));
        for(int i = 0; i < A.size(); ++i)
        {
            for(int j = 0; j < A[0].size(); ++j)
                ret[j][i] = A[i][j];
        }
        return ret;
    }
};

/*
An easy level algorithm issue.
Time Complexity is: O(m*n)
Space Complexity is: O(m*n)
*/
