class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        /* time complexity is O(n) */
        vector<int> ret;
        if(A.size() == 0)
            return ret;
        int i = 0, j = A.size()-1;
        while(i <= j)
        {
            if(abs(A[i]) < abs(A[j]))
            {
                ret.insert(ret.begin(), A[j]*A[j]);
                --j;
            }
            else
            {
                ret.insert(ret.begin(), A[i]*A[i]);
                ++i;
            }
        }
        return ret;
    }
};


/*
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
