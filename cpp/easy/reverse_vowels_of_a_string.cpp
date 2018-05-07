class Solution {
public:
    string reverseVowels(string s) {
        if(s.size() == 0 || s.size() == 1)
            return s;
        int start = 0;
        int end = s.size()-1;
        while(start < end)
        {
            if(is_vowel(s[start]) && is_vowel(s[end]))
            {
                char tmp = s[start];
                s[start] = s[end];
                s[end] = tmp;
                ++start;
                --end;
            }
            while(start < end && !is_vowel(s[start]))
                ++start;
            while(start < end && !is_vowel(s[end]))
                --end;
            
        }
        return s;
    }
    
    bool is_vowel(char s)
    {
        s = tolower(s);
        if(s == 'a') return true;
        else if(s == 'e') return true;
        else if(s == 'i') return true;
        else if(s == 'o') return true;
        else if(s == 'u') return true;
        elsereturn false;
    }
};


Conclusion:
an easy leetcode algorithm issue, no comments.

Time Complexity: O(n)
Space Complexity: O(1)
