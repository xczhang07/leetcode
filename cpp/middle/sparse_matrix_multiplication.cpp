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


Solution 2:
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        int n = A[0].size();
        int k = B[0].size();
        vector<vector<int>> ret(m, vector<int>(k, 0));
        unordered_map<int,int> mapA;
        unordered_map<int,int> mapB;
        /* convert two dimision array to one dimision array */
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(A[i][j] != 0)
                    mapA[i*n + j] = A[i][j];
            }
        }
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < k; ++j)
            {
                if(B[i][j] != 0)
                    mapB[i*k+j] = B[i][j];
            }
        }
        
        /*****
        
        assume A is m * n two dimission array, B is n * k two dimission array.
        A * B => C[0][0] = (A[0][0]*B[0][0] + A[0][1]*B[1][0] + A[0][2]*B[2][0] +...+A[0][n-1]*B[n-1][0])
                 C[1][1] = (A[1][0]*B[0][1] + A[1][1]*B[1][1] + A[1][2]*B[2][1] +...+A[1][n-1]*B[n-1][1])
                 ...
                 C[m-1][k-1] = (A[m-1][0]*B[0][k-1] + A[m-1][1]*B[1][k-1] + A[m-1][2]*B[2][k-1] +...+A[m-1][n-1]*B[n-1][k-1])
        
        *****/
        for(auto a : mapA)
        {
            int row_a = a.first/n;
            int col_a = a.first%n;
            for(auto b : mapB)
            {
                int row_b = b.first/k;
                int col_b = b.first%k;
                if(col_a == row_b)
                    ret[row_a][col_b] += A[row_a][col_a] * B[row_b][col_b];
            }
        }
        return ret;
        
    
    }
    
};
