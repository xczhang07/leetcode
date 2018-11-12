class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        stack<pair<int,int>> st;
        int curr_len = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
                st.push(make_pair(i,0));
            else if(s[i] == ')')
            {
                if(st.empty() || st.top().second == 1)
                    st.push(make_pair(i, 1));
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

/*
Time Complexity is: O(n)
Space Complexity is: O(n)
reference link : http://bangbingsyb.blogspot.com/2014/11/leetcode-longest-valid-parentheses.html
*/
