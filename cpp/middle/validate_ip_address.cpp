class Solution {
public:
   bool isValidIPv4Part(string &s) {
        if (s.length() < 1 || s.length() > 3)
            return false;
        
        if (s[0] == '0' && s.length() != 1)
            return false;
        
        int val = 0;
        for (char c : s) {
            if (!isdigit(c))
                return false;
            val = val * 10 + c - '0';
        }
        return val < 256;
    }
    
    bool isValidIPv6Part(string &s) {
        if (s.length() < 1 || s.length() > 4)
            return false;
        
        for (char c : s) {
            if (!isxdigit(c))
                return false;
        }
        return true;
    }

    vector<string> split(string &s, char d) {
        stringstream ss(s);
        vector<string> ans;
        string t;
        while (!ss.eof()) {
            getline(ss, t, d);
            ans.push_back(t);
        }
        return ans;
    }

    bool isValidIPv4Address(string &IP) {
        if (IP.length() < 7 || IP.length() > 15)
            return false;
        
        vector<string> parts = split(IP, '.');
        if (parts.size() != 4)
            return false;
        for (string &part : parts) {
            if (!isValidIPv4Part(part))
                return false;
        }
        return true;
    }
    
    bool isValidIPv6Address(string &IP) {
        if (IP.length() < 15 || IP.length() > 39)
            return false;
        
        vector<string> parts = split(IP, ':');
        if (parts.size() != 8)
            return false;
        for (string &part : parts) {
            if (!isValidIPv6Part(part))
                return false;
        }
        return true;
    }

    string validIPAddress(string IP) {
        if (isValidIPv4Address(IP))
            return "IPv4";
        
        if (isValidIPv6Address(IP))
            return "IPv6";
        
        return "Neither";
    }
};

/*
Conclusion:
a middle level algorithm issue, check a input string whether or not is an valid ipv4 or ipv6 string
*/


Solution 2:
an easy solution, one function work out this issue.
   class Solution {
public:

    string validIPAddress(string IP) {
        istringstream ss(IP);
        string t = "";
        int cnt = 0;
        if(IP.find(":") == string::npos) /* input ip address is ipv4 */
        {
            while(getline(ss, t, '.'))
            {
                ++cnt;
                if(cnt > 4)
                    return "Neither";
                if(t.size() == 0 || t.size() > 3 || (t[0] == '0' && t.size() > 1))
                    return "Neither";
                for(int i = 0; i < t.size(); ++i)
                {
                    if(t[i] < '0' || t[i] > '9')
                        return "Neither";
                }
                int num = stoi(t);
                if(num < 0 || num > 255)
                    return "Neither";
            }
            return (cnt == 4 && IP.back()!='.') ? "IPv4":"Neither";
        }
        else /* input ip address is ipv6 */
        {
            while(getline(ss, t, ':'))
            {
                ++cnt;
                if(cnt > 8)
                    return "Neither";
                if(t.size() == 0 || t.size() > 4)
                    return "Neither";
                for (char c : t) {
                    if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return "Neither";
                }
            }
            return (cnt == 8 && IP.back() != ':') ? "IPv6" : "Neither";
        }
    }
};
