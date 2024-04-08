class Solution {
public:
     bool isNumber(string s) {
         if(s.size() == 0)
             return false;
         int start = 0;
         int end = s.size()-1;
         while(s[start] == ' ') ++start;
         while(s[end] == ' ') --end;
         if(s[start] == '-' || s[start] == '+') ++start;
         if(start > end) return false;
         bool isdot = false;
         bool ise = false;
         for(int i = start; i <= end; ++i)
         {
             if(s[i] == '.')
             {
                 if(start == end) return false;
                 if(isdot || ise) return false;
                 isdot = true;
             }
             else if(s[i] == 'e')
             {
                 if(i == start || i == end) return false;
                 if(s[i-1] == '.' && i-1 == start) return false;
                 if(ise) return false;
                 ise = true;
             }
             else if(s[i] >= '0' && s[i] <= '9') continue;
             else if(s[i] == '+' || s[i] == '-')
             {
                 if(s[i-1] != 'e' || i == end) return false;
             }
             else return false;
         }
         return true;
    }
};


the solution version without e as following:
bool isNumber(string s) {
    /* preprocessing */
    if(s.size() == 0)
        return false;
    int start = 0;
    int end = s.size()-1;
    while(s[start] == ' ')
        ++start;
    while(s[end] == ' ')
        --end;
    if(s[start] == '+' || s[start] == '-')
        ++start;
    if(start > end)
        return false;
    bool is_dot = false;
    for(int i = start; i <= end; ++i)
    {
        if(s[i] >= '0' && s[i] <= '9')
            continue;
        else if(s[i] == '.')
        {
            if(start == end)
                return false;
            if(is_dot)
                return false;
            is_dot = true;
        }
        else
            return false;
    }
    return true;
}

// The version without e/E
bool isValidNumber(string& num) {
    if(num.size() == 0) {
        return false;
    }
    int i = 0;
    int j = num.size()-1;
    if(num[i] == '+' || num[i] == '-') {
        ++i;
    }
    if(i==j && (num[i] == '.')) {
        return false;
    }
    if(num[j] == '+' || num[j] == '-') {
        return false;
    }
    bool hasDot = false;
    for(int k = i; k <= j; ++k) {
        if(num[k] == '.') {
            if(hasDot) {
                return false;
            }
            hasDot = true;
        } else if(num[k] >= '0' && num[k] <= '9') {
            continue;
        } else if(num[k] == '+' || num[k] == '-') {
            return false;
        } else {
            return false;
        }
    }
    return true;
}
