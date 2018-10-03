class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        if(tokens.size() == 0)
            return 0;
        int num1 = 0;
        int num2 = 0;
        for(int i = 0; i < tokens.size(); ++i)
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
                st.push(stoi(tokens[i]));
            else
            {
                num2 = st.top();
                st.pop();
                num1 = st.top();
                st.pop();
                if(tokens[i] == "+")
                    st.push(num1 + num2);
                else if(tokens[i] == "*")
                    st.push(num1 * num2);
                else if(tokens[i] == "-")
                    st.push(num1-num2);
                else if(tokens[i] == "/")
                    st.push(num1/num2);
            }
        }
        return st.top();
    }
};

/*
Conclusion:
a middle level algorithm issue, not diffcult, we can use one pass to resolve this issue.
Time Complexity: O(n)
Space Complexity: O(n)
*/
