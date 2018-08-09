class Solution {
public:
   bool backspaceCompare(string S, string T) {
        int i = S.size()-1;
        int j = T.size()-1;
        int A = 0;
        int B = 0;
        while(i >= 0 || j >= 0)
        {
            while(i >= 0 && (S[i] == '#' || A > 0))
            {
                if(S[i] == '#')
                    ++A;
                else
                    --A;
                --i;
            }
            while(j >= 0 && (T[j] == '#' || B > 0))
            {
                if(T[j] == '#')
                    ++B;
                else
                    --B;
                --j;
            }
            if(i < 0 || j < 0)
                return i == j;
            if(S[i] != T[j])
                return false;
            --i;
            --j;
        }
       return true;
    }
};


Conclusion:
an easy level question, using two pointers to travel the string.
Time Complexity: O(n)
Space Complexity: O(1)
