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
