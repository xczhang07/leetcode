Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.


Time Complexity is: O(n)
space complexity is: O(n)

class Solution {
public:
    string minWindow(string s, string t) {
        string min_str;
        if(s.size() == 0 || t.size() == 0)
            return min_str;
        unordered_map<char, int> m;
        int len = 0;
        int min_len = INT_MAX;
        int start = 0;
        for(char c : t)
            m[c]++;
        for(int i = 0; i < s.size(); ++i)
        {
            m[s[i]]--;
            if(m[s[i]] >= 0)
                ++len;
            while(len == t.size())
            {
                int tmp_len = i-start+1;
                if(tmp_len < min_len)
                {
                    min_len = tmp_len;
                    min_str = s.substr(start, min_len);
                }
                m[s[start]]++;
                if(m[s[start]] > 0)
                    --len;
                ++start;
            }
        }
        return min_str;
    }
};
