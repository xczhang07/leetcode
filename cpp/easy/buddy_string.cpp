class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
            return false;
        if(A.size() == 0 || B.size() == 0)
            return false;
        int idx1 = 0;
        int idx2 = 1;
        int times = 0;
        bool dup = false;
        vector<int> m(26,0);
        for(int i = 0; i < A.size(); ++i)
        {
            if(A[i] == B[i])
            {
                m[A[i]-'a']++;
                if(m[A[i]-'a'] > 1)
                    dup = true;
            }
            else
            {
                ++times;
                if(times > 2)
                    return false;
                if(times == 1)
                   idx1 = i;
                if(times == 2)
                    idx2 = i;
            }
        }
        
        if(times == 2 && A[idx1] == B[idx2] && A[idx2] == B[idx1])
            return true;
        else if(dup)
            return true;
        else
            return false;
    }
};
