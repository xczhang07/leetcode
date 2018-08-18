class Solution {
public:
    bool isStrobogrammatic(string num) {
        if(num.size() == 0)
            return true;
        unordered_map<char,char> m;
        m['6'] = '9';
        m['9'] = '6';
        m['1'] = '1';
        m['0'] = '0';
        m['8'] = '8';
        string ret;
        for(auto s : num)
        {
            if(m.find(s) != m.end())
                ret.push_back(m[s]);  // we need to put the m[s] instead of s!
            else
                return false;
        }
        reverse(ret.begin(), ret.end());
        return ret == num;
    }
};


Conclusion: an easy level algorithm issue, we need to understand the pairs are: {0,0}, {1,1}, {6,9}, {8,8}, {9,6}

Time Complexity: O(n)
Space Complexity: O(n)

