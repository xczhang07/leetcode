class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if(word1.empty()) {
            return word2;
        } else if(word2.empty()) {
            return word1;
        }
        int idx1 = 0, idx2 = 0;
        string ret;
        while(idx1 < word1.size() && idx2 < word2.size()) {
            ret.push_back(word1[idx1]);
            ret.push_back(word2[idx2]);
            ++idx1;
            ++idx2;
        }
        while(idx1 < word1.size()) {
            ret.push_back(word1[idx1]);
            ++idx1;
        }
        while(idx2 < word2.size()) {
            ret.push_back(word2[idx2]);
            ++idx2;
        }
        return ret;
    }
};
