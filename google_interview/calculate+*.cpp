面经题，+ * 计算，( * 2 7 ( + 3 4 8 ) 8 )

int calculate(string s)
{
    if(s.size() == 0)
        return 0;
    stack<char> ops;
    stack<string> st;
    char op = '#';
    int num = 0;
    for(int i = 0; i < s.size(); ++i)
    {
       if(s[i] == '(')
       {
           if(op != '#')
           {
               ops.push(op);
               st.push(to_string(num));
           }
           st.push("(");
       }
        else if(s[i] == '+' || s[i] == '*')
        {
            if(s[i] == '+')
                num = 0;
            else
                num = 1;
            op = s[i];
        }
        else if(isdigit(s[i]))
        {
            if(op == '*')
                num *= (s[i]-'0');
            else
                num += (s[i]-'0');
        }
        else if(s[i] == ')')
        {
            while(!st.empty() && st.top()!="(")
            {
                int tmp = stoi(st.top());
                st.pop();
                if(op == '*')
                    num *= tmp;
                else
                    num += tmp;
            }
            if(!st.empty())
                st.pop();
            st.push(to_string(num));
            if(!ops.empty())
            {
                op = ops.top();
                ops.pop();
            }
            if(op == '*')
                num = 1;
            else
                num = 0;
        }
    }
    int ret = stoi(st.top());
    return ret;
}
