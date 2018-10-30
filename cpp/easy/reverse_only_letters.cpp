class Solution {
public:
    string reverseOnlyLetters(string S) {
        if(S.size() <= 1)
            return S;
        int start = 0;
        int end = S.size()-1;
        while(start < end)
        {
            while(start < end && !isalpha(S[start]))
                ++start;
            while(start < end && !isalpha(S[end]))
                --end;
            char tmp = S[start];
            S[start] = S[end];
            S[end] = tmp;
            ++start;
            --end;
        }
        return S;
    }
};


/*
an easy level algorithm issue.
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
