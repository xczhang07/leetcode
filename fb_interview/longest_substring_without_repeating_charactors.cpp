Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
             
Time Complexity is: O(n)
Space Complexity is: O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1)
            return s.size();
        unordered_map<char,int> window;
        int start = 0;
        int max_len = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(!window.count(s[i]))
            {
                window[s[i]] = i;
                max_len = max(max_len, i-start+1);
            }
            else
            {
                start = max(start, window[s[i]]+1);
                window[s[i]] = i;
                max_len = max(max_len, i-start+1);
            }
        }
        return max_len;
    }
};
