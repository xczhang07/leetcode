A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)
            return 0;
        /*
        3 cases:
        case 1: 1-9 generate one
        case 2: 10, 20, one solution
        case 3: 11-19, 21-26 two solution
        */
        int prev = 1;
        int curr = 0;
        int pprev = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && (s[i]-'0' <= 6))))
            {
                if(s[i] == '0')
                    curr = pprev;
                else
                    curr = prev + pprev;
            }
            else if(s[i] == '0')
                return 0;
            else
                curr = prev;
            pprev = prev;
            prev = curr;
        }
        return curr;
    }
};
