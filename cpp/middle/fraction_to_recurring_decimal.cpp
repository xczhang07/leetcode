class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        if(!denominator) return "";
        string ret;
        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            ret = "-" + ret;
        long n = abs((long)numerator);
        long d = abs((long)denominator);
        long rest = n%d;
        ret = ret + to_string(n/d);
        if(!rest)
            return ret;
        ret.push_back('.');
        unordered_map<long, int> m;
        while(rest)
        {
            if(m.count(rest))
            {
                ret.insert(m[rest],"(");
                ret.push_back(')');
                return ret;
            }
            m[rest] = ret.size();
            rest *= 10;
            ret = ret + to_string(rest/d);
            rest %= d;
        }
        return ret;
    }
};
