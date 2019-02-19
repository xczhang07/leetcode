string removeInvalidParentheses(string s)
{
    if(s.size() == 0)
        return "";
    int left = 0, right = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '(')
            ++left;
        else if(s[i] == ')')
        {
            if(left > 0)
                --left;
            else
                ++right;
        }
    }
    
    int idx = 0;
    while(idx < s.size())
    {
        if(s[idx] == '(' && left > 0)
        {
            --left;
            s.erase(idx,1);
        }
        else if(s[idx] == ')' && right > 0)
        {
            --right;
            s.erase(idx, 1);
        }
        else
            ++idx;
    }
    
    return s;
}
