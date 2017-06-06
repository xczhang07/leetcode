class Solution {
public:
    string reverseString(string s) {
        if(s.size() == 0 || s.size() == 1)
            return s;
        int i = 0;
        int j = s.size()-1;
        while(i < j)
        {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            ++i;
            --j;
        }
        return s;
    }
};
