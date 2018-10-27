class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size() <= 1)
            return A;
        vector<int> ret;
        for(int i = 0; i < A.size(); ++i)
        {
            if(A[i]%2 == 0)
                ret.insert(ret.begin(), A[i]);
            else
                ret.push_back(A[i]);
        }
        return ret;
    }
};

/*
easy algorithm issue.
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
