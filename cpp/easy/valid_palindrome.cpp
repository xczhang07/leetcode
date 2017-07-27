class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() <= 1)
            return true;
        string tmpstr = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int start = 0;
        int end = s.size()-1;
        while(start < end)
        {
            while(start < end && tmpstr.find(s[start]) == string::npos)
                ++start;
            while(start < end && tmpstr.find(s[end]) == string::npos)
                --end;
            s[start] = std::tolower(s[start]);
            s[end] = std::tolower(s[end]);
            if(s[start] == s[end])
            {
                ++start;
                --end;
            }
            else
                return false;
        }
        return true;
    }
};


Conclusion:
an easy algorithm issue, create a tmp string as a template dictionary to check whether or not an element is alphanumeric charactors.
Time Complexity is: O(n)
Space Complexity is: O(1)
