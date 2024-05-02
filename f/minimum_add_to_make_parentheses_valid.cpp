Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

class Solution {
public:
    int minAddToMakeValid(string S) {
        if(S.size() == 0)
            return 0;
        if(S.size() == 1)
            return 1;
        stack<char> st;
        for(int i = 0; i < S.size(); ++i)
        {
            if(st.empty())
                st.push(S[i]);
            else
            {
                if(S[i] == ')' && st.top() == '(')
                    st.pop();
                else
                    st.push(S[i]);
            }
        }
        
        return st.size();
    }
};

Time Complexity is: O(n)
Space Complexity is: O(n)

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                open += 1;
            } else {
                close += 1;
                if(open > 0) {
                    open -= 1;
                    close -= 1;
                }
            }
        }
        return open + close;
    }
};

Time Complexity is: O(n)
Space Complexity is: O(1)
