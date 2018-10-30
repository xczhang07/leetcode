class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> m;
        int ret = 0;
        for(int i = 0; i < A.size(); ++i)
        {
            for(int j = 0; j < B.size(); ++j)
                m[A[i]+B[j]]++;
        }
        for(int i = 0; i < C.size(); ++i)
        {
            for(int j = 0; j < D.size(); ++j)
            {
                int rest = 0-C[i]-D[j];
                if(m.find(rest) != m.end())
                    ret += m[rest];
            }
        }
        return ret;
    }
};


/*
Conclusion: an middle level algorithm issue.
Time Complexity is: O(n^2)
Space Complexity is: O(n)
*/
