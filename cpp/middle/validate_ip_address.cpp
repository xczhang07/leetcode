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
