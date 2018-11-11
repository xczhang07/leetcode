class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if(A.size() == 1)
            return 0;
        sort(A.begin(), A.end());
        
        int n = A.size()-1;
        int diff = A[n]-A[0];
        if(K == 0)
            return diff;
        else if(diff > K)
        {
            int val = A[n]-A[0]-K;
            if(val > K)
                return val-K;
            else
                return 0;
        }
        else
            return 0;
    }
};
