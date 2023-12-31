class Solution {
public:
    string removeDuplicates(string s) {
        // Corner case check, no duplication possibility.
        if(s.size() < 2) {
            return s;
        }
        string ret = "";
        for(char& e: s) {
            if(ret.size() > 0 && (e == ret.back())) {
                ret.pop_back();
            } else {
                ret.push_back(e);
            }
        }
        return ret;
    }
};
