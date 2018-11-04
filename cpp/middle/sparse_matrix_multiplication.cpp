class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));
        for(int i = 0; i < A.size(); ++i)
        {
            for(int j = 0; j < A[0].size(); ++j)
            {
                if(A[i][j] != 0)
                {
                    for(int k = 0; k < B[0].size(); ++k)
                    {
                        if(B[j][k]!=0)
                        {
                            res[i][k] += A[i][j]*B[j][k];
                        }
                    }
                }
            }
        }
        return res;
    }
    
};
