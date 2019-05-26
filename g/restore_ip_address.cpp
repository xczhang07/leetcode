Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]

class Solution {
public:
    bool validIp(string ip)
    {
        if(ip.size() > 1 && ip[0] == '0')
            return false;
        int num = stoi(ip);
        if(num > 255)
            return false;
        return true;
    }
    
    void buildIpAddr(vector<string>& ret, string ip, string s, int k)
    {
        if(k == 0)
        {
            if(s.size() == 0)
                ret.push_back(ip);
            return;
        }
        for(int i = 1; i <= 3; ++i)
        {
            if(s.size() >= i && validIp(s.substr(0,i)))
            {
                string next = s.substr(i);
                if(k == 1)
                    buildIpAddr(ret, ip+s.substr(0,i), next, k-1);
                else
                    buildIpAddr(ret, ip+s.substr(0,i)+'.', next, k-1);
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string ip;
        int k = 4;
        buildIpAddr(ret, ip, s, k);
        return ret;
    }
};
