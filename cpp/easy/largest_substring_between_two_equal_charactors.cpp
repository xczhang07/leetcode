class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        if(s.size() < 2) {
            return -1;
        }
        int longest_len = -1;
        unordered_map<char, int> idx_map;
        for(int i = 0; i < s.size(); ++i) {
            if(idx_map.find(s[i]) != idx_map.end()) {
                int tmp_length = i - idx_map[s[i]] - 1;
                longest_len = max(longest_len, tmp_length);
            } else {
                idx_map[s[i]] = i;
            }
        }
        return longest_len;
    }
};
