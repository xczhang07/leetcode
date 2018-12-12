class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() == 0)
            return true;
        bool flag1 = true;
        bool flag2 = true;
        for(int i = 0; i < A.size()-1; ++i)
        {
            if(A[i] <= A[i+1])
                continue;
            else
            {
                flag1 = false;
                break;
            }
        }
        for(int i = 0; i < A.size()-1; ++i)
        {
            if(A[i] >= A[i+1])
                continue;
            else
            {
                flag2 = false;
                break;
            }
        }
        return flag1||flag2;
        
    }
};
