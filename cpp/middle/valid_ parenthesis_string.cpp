class Solution {
public:
    bool checkValidString(string s) {
        if(s.size() == 0) 
            return true;
        int left = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '*' || s[i] == '(')
                ++left;
            else
            {
                --left;
                if(left < 0) return false;
            }
        }
        if(left == 0) return true;
        int right = 0;
        for(int i = s.size()-1; i >= 0; --i)
        {
            if(s[i] == '*' || s[i] == ')')
                ++right;
            else
            {
                --right;
                if(right < 0) return false;
            }
        }
        return true;
    }
};

/*
x is the number of '(', and y is the number of ')', m is the number of '*'
it should meets the following requirements:
x + m >= y
y + m >= x
*/
