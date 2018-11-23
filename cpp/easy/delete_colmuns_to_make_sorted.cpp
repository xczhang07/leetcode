class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if(A.size() == 0)
            return 0;
        if(A[0].size() == 0)
            return 0;
        int n = A[0].size();
        int m = A.size();
        int i = 0;
        int j = 0;
        vector<int> indices;
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < m-1; ++j)
            {
                if(A[j][i] <= A[j+1][i])
                    continue;
                else
                    break;
            }
            if(j != m-1)
                indices.push_back(i);
        }
        return indices.size();
    }
};
