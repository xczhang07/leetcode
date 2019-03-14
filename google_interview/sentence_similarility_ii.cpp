class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size())
            return false;
        unordered_map<string,string> parent;
        for(auto p : pairs)
        {
            parent[p.first] = p.first;
            parent[p.second] = p.second;
        }
        
        for(auto p : pairs)
        {
            string p1 = findParent(parent, p.first);
            string p2 = findParent(parent, p.second);
            if(p1 != p2)
                parent[p2] = p1;
        }
        
        for(int i = 0; i < words1.size(); ++i)
        {
            string p1 = findParent(parent, words1[i]);
            string p2 = findParent(parent, words2[i]);
            if(p1 != p2)
                return false;
        }
        
        return true;
    }
    
    
    string findParent(unordered_map<string,string>& parent, string& word)
    {
        while(parent[word] != word)
            word = parent[word];
        return word;
    }
    
    
};
