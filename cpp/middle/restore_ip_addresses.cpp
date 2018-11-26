class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if(s.size() == 0)
            return ret;
        string ip;
        int k = 4;
        restore(ret, k, ip, s);
        return ret;
    }
    
    
    void restore(vector<string>& ip_pool, int k, string ip, string s)
    {
        if(k == 0)
        {
            if(s.size() == 0)
            {
                ip_pool.push_back(ip);
                //return;
            }
        }
        else {
            for(int i = 1; i <= 3; ++i)
            {
                if(s.size() >= i && valid_ip(s.substr(0,i)))
                {
                    if(k == 1)
                        restore(ip_pool, k-1, ip+s.substr(0,i), s.substr(i));
                    else
                        restore(ip_pool, k-1, ip+s.substr(0,i)+".", s.substr(i));
                }
            }
        }
        return;
    }
    
    bool valid_ip(string ip)
    {
        if(ip.size() == 0)
            return false;
        else if(ip[0] == '0' && ip.size() > 1)
            return false;
        else
        {
            int num = stoi(ip);
            if(num < 0 || num > 255)
                return false;
            return true;
        }
    }
};
