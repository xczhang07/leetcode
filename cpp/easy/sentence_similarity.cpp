class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size())
            return false;
        if(pairs.size() == 0)
        {
            if(words1 == words2)
                return true;
            else
                return false;
        }
        for(int i = 0; i < words1.size(); ++i)
        {
            string word1 = words1[i];
            string word2 = words2[i];
            if(word1 == word2)
                continue;
            if(std::find(pairs.begin(), pairs.end(), make_pair(word1, word2)) == pairs.end() && find(pairs.begin(), pairs.end(), make_pair(word2, word1)) == pairs.end())
                return false;
        }
        return true;
    }
};


Conclusion: an easy algorithm issue. No any other comments.
