class Solution {
public:
    char findTheDifference(string s, string t) {
        if(t.size() <= s.size())
            return NULL;
        char ret = 0;
        for(char m : s) ret ^= m;
        for(char n : t) ret ^= n;
        return ret;
    }
};


Conclustion:
easy, no any other comments
