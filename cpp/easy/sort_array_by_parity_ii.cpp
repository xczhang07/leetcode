class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> ret(A.size(), 0);
        int even = 0;
        int odd = 1;
        for(int i = 0; i < A.size(); ++i)
        {
            if(A[i] % 2 == 0)
            {
                ret[even] = A[i];
                even += 2;
            }
            else
            {
                ret[odd] = A[i];
                odd += 2;
            }
        }
        return ret;
    }
};

/*
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
