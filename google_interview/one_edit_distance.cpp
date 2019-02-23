Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.


class Solution {
public:
     bool isOneEditDistance(string s, string t) {
         if(s.size() < t.size())
            swap(s, t);
         int ls = s.size();
         int lt = t.size();
         
         if(ls - lt >= 2)
             return false;
         if(ls == lt)
         {
             int cnt = 0;
             for(int i = 0; i < ls; ++i)
             {
                 if(s[i] != t[i])
                 {
                     if(cnt == 1)
                         return false;
                     cnt++;
                 }
             }
             return cnt == 1;
         }
         else
         {
             for(int i = 0; i < lt; ++i)
             {
                 if(s[i] != t[i])
                     return s.substr(i+1) == t.substr(i);
             }
             return true;
         }
    }
    
};
