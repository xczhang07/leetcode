class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() <= 1)
            return 0;
        sort(A.begin(), A.end());
        int ret = 0;
        for(int i = 1; i < A.size(); ++i)
        {
            if(A[i-1] >= A[i])
            {
                ret += (A[i-1]-A[i]+1);
                A[i] = A[i-1]+1;
            }
        }
        return ret;
    }
    
    
    
};

/*
Time Complexity is: O(nlogn)
Space Complexity is: O(1)
*/
