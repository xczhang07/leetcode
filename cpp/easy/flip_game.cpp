class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        if(s.size() <= 1)
            return {};
        vector<string> ret;
        for(int i = 0; i < s.size()-1; ++i)
        {
            if(s[i] == '-')
                continue;
            string tmp = s;
            if(s[i] == '+' && s[i+1] == '+')
            {
                tmp[i] = '-';
                tmp[i+1] = '-';
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};

/*
an easy algorithm issue.
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
