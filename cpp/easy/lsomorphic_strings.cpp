class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /* invalidation check */
        if(s.size() != t.size())
            return false;
        /* we need to map for this issue because this question requires 1 to 1 mapping, 
        which does not require n to 1 maps, for example, s = "ab", t = "aa", which does not
        stasify the requirements */
        unordered_map<char,char> stot;
        unordered_map<char,char> ttos;
        for(int i = 0; i < s.size(); ++i)
        {
            if(stot.find(s[i]) == stot.end())
                stot[s[i]] = t[i];
            else
            {
                if(stot[s[i]] != t[i])
                    return false;
            }
            if(ttos.find(t[i]) == ttos.end())
                ttos[t[i]] = s[i];
            else
            {
                if(ttos[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};


Conclusion: easy algorithm issue. no comments.

Time Complexity: O(n)
Space Complexity: O(n)
