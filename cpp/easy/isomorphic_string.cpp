class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        char map_s[256] = {0};
        char map_t[256] = {0};
        int n = s.size();
        for(int i = 0; i < n; ++i)
        {
            if(map_s[s[i]] != map_t[t[i]])
                return false;
            if(map_s[s[i]] == 0 && map_t[t[i]] == 0)
            {
                map_s[s[i]] = i+1;
                map_t[t[i]] = i+1;
            }
        }
        return true;
    }
};
