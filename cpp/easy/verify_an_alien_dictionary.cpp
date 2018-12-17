class Solution {
public:
    vector<int> m;
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() < 2) return true;
        m = vector<int>(26,0);
        for(int i = 0; i < order.size(); ++i)
            m[order[i]-'a'] = i;
        for(int i = 0; i < words.size()-1; ++i)
        {
            if(!is_order(words[i], words[i+1]))
                return false;
        }
        return true;
    }
    
    bool is_order(string& word1, string& word2)
    {
        int i = 0, j = 0;
        while(i < word1.size() && j < word2.size())
        {
            if(word1[i] != word2[j])
            {
                int p1 = m[word1[i]-'a'];
                int p2 = m[word2[j]-'a'];
                if(p2 < p1) 
                    return false;
                if(p2 > p1) 
                    return true;
            }
            ++i;
            ++j;
        }
        return word1.size() <= word2.size();
    }
};
