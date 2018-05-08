class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        for(int i = 1; i <= len/2; ++i)
        {
            if(len % i == 0)
            {
                string str1 = s.substr(i);
                string str2 = s.substr(0,len-i);
                if(str1 == str2)
                    return true;
            }
        }
        return false;
    }
};

Conclusion: an easy algorithm issue of leetcode; however, IMO, it is not belongs to easy algorithm question. above method is a smart way
to resolve this issue, assume we shift the i index of the input string, x = s.substr(i), y = s.substr(0,s.size()-i). 

Time Complexity: O(n/2) => O(n)
Space Complexity: O(1)
