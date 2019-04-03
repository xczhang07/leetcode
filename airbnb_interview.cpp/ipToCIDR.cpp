class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) 
    {
        vector<string> ret;
        if(ip.size() == 0)
            return ret;
        istringstream s(ip);
        long num = 0;
        string tmp;
        while(getline(s, tmp, '.'))
        {
            num = num*256 + stoi(tmp);
        }
        
        while(n > 0)
        {
            long step = num & -num;
            while(step > n)
                step /= 2;
            ret.push_back(convert(num, step));
            num += step;
            n -= step;
        }
        
        return ret;
    }
    
    string convert(int num, int step)
    {
        return to_string((num>>24)&255) + "." + to_string((num>>16)&255) + "." + to_string((num>>8)&255) + "." + to_string(num&255) + "/"
            +to_string(32-(int)log2(step));
    }
   
};
