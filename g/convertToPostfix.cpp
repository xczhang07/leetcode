 Postfix，这题把所有可能的运算符全扔上去了，比如input = (a+b*c+(d*e^f+h)), output = abc*+def^*h++, 按优先级把运算符甩到两个字符后边去

int priority(char op)
{
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string convertToPostfix(string infix)
{
    if(infix.size() == 0)
        return "";
    string postfix;
    stack<char> st;
    for(int i = 0; i < infix.size(); ++i)
    {
        if(infix[i] == '(')
            st.push(infix[i]);
        else if(isalpha(infix[i]))
            postfix.push_back(infix[i]);
        else if(infix[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                postfix.push_back(st.top());
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }
        else
        {
            while(!st.empty() && priority(infix[i]) <= priority(st.top()))
            {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    
    while(!st.empty())
    {
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}
