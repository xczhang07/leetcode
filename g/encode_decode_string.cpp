string encodeString(string input)
{
    if(input.size() == 0)
        return "";
    int cnt = 1;
    string encode_str;
    char c = input[0];
    for(int i = 1; i < input.size(); ++i)
    {
        if(input[i] == c)
            cnt++;
        else
        {
            if(cnt > 1)
            {
                encode_str += to_string(cnt);
                encode_str.push_back('x');
            }
            encode_str.push_back(c);
            c = input[i];
            cnt = 1;
        }
    }
    if(cnt > 1)
    {
        encode_str += to_string(cnt);
        encode_str.push_back('x');
    }
    encode_str.push_back(c);
    return encode_str;
}

string decodeString(string input)
{
    if(input.size() == 0)
        return "";
    int idx = 0;
    int num = 0;
    string ret;
    while(idx < input.size())
    {
        if(isdigit(input[idx]))
        {
            num = 0;
            while(idx < input.size() && isdigit(input[idx]))
            {
                num = num*10 + (input[idx]-'0');
                idx++;
            }
            ++idx; /* skip 'x' */
            ret += string(num, input[idx]);
            ++idx;
        }
        else if(!isdigit(input[idx]) && input[idx] != 'x')
        {
            ret.push_back(input[idx]);
            ++idx;
        }
    }
    
    return ret;
}
