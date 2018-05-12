class Solution {
public:
    bool isValid(string s) {
        /* corner case check */
        if(s.size() % 2 != 0) return false;
        else if(s.size() == 0) return true;
        stack<char> st;
        st.push(s[0]);
        int i = 1;
        char top;
        while(!st.empty() && i < s.size())
        {
            top = st.top();
            char tmp = s[i];
            if(tmp == ')')
            {
                if(st.empty()) return false;
                st.pop();
                if(top != '(') return false;
            }
            else if(tmp == ']')
            {
                if(st.empty()) return false;
                st.pop();
                if(top != '[') return false;
            }
            else if(tmp == '}')
            {
                if(st.empty()) return false;
                st.pop();
                if(top != '{') return false;
            }
            else
                st.push(s[i]);
            i++;
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};

Conclusion: check whether or not the input string is a valid parentheses, eg "(())" is valid, ")(" is invalid.

Time Complexity: O(n)
Space Complexity: O(n) extra space stack requires,
