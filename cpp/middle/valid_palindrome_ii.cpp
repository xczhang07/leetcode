class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l < r)
        {
            if(s[l] != s[r])
            {
                bool ret = isPalindrome(s, l+1, r) || isPalindrome(s, l, r-1);
                if(ret) return true;
                else
                    return false;
            }
            ++l;
            --r;
        }
        return true;
    }
    
    bool isPalindrome(string& s, int l, int r)
    {
        while(l < r)
        {
            if(s[l] != s[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }
};
