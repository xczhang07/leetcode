Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

Time Complexity is: O(n)
Space Complexity is: O(n)

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0)
            return 0;
        int max_len = 0;
        int curr_len = 0;
        
        stack<pair<int,char>> st;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
                st.push(make_pair(i, s[i]));
            else
            {
                if(st.empty() || st.top().second == ')')
                    st.push(make_pair(i, s[i]));
                else
                {
                    st.pop();
                    if(st.empty())
                        curr_len = i+1;
                    else
                        curr_len = i-st.top().first;
                    max_len = max(max_len, curr_len);
                }
            }
        }
        return max_len;
    }
};
