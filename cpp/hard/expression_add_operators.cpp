class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        string out;
        dfs(ret, num, 0, 0, out, target);
        return ret;
    }
    
    void dfs(vector<string>& ret, string num, long long diff, long long curr, string out, int& target)
    {
        if(num.size() == 0 && curr == target)
        {
            ret.push_back(out);
            return;
        }
        for(int i = 1; i <= num.size(); ++i)
        {
            string digit = num.substr(0,i);
            if(digit.size() > 1 && digit[0] == '0')
                return;
            string next = num.substr(i);
            if(out.size() > 0)
            {
                dfs(ret, next, stoll(digit), curr+stoll(digit), out+"+"+digit, target);
                dfs(ret, next, -stoll(digit), curr-stoll(digit), out+"-"+digit, target);
                dfs(ret, next, diff*stoll(digit), curr-diff + diff*stoll(digit), out+"*"+digit, target);
            }
            else
                dfs(ret, next, stoll(digit), curr+stoll(digit), digit, target);
        }
    }
};
