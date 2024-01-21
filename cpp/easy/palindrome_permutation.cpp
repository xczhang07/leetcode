class Solution {
public:
    bool canPermutePalindrome(string s) {
        if(s.size() == 0) {
            return true;
        }
        vector<int> alpha_map(26, 0);
        for(int i = 0; i < s.size(); ++i) {
            alpha_map[s[i]-'a']++;
        }
        int odd_num = 0;
        for(int i = 0; i < alpha_map.size(); ++i) {
            if(alpha_map[i]%2 != 0) {
                ++odd_num;
            }
        }
        if(odd_num > 1) {
            return false;
        }
        return true;
    }
};
