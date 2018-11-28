class Solution {
public:
    string decodeString(string s) {
        if(s.size() == 1)
            return s;
        stack<int> nums;
        stack<string> chars;
        string ret;
        int num = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(isdigit(s[i]))
                num = num * 10 + s[i]-'0';
            else if(isalpha(s[i]))
                ret.push_back(s[i]);
            else if(s[i] == '[')
            {
                nums.push(num);
                chars.push(ret);
                ret.clear();
                num = 0;
            }
            else if(s[i] == ']')
            {
                string tmp = ret;
                for(int i = 0; i < nums.top()-1; ++i)
                    ret += tmp;
                ret = chars.top() + ret;
                nums.pop();
                chars.pop();
            }
        }
        return ret;
    }
    
    
};
