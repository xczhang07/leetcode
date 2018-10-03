class WordDistance {
public:
    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); ++i)
            container[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int min_distance = INT_MAX;
        vector<int> wp1 = container[word1];
        vector<int> wp2 = container[word2];
        int i = 0;
        int j = 0;
        while(i < wp1.size() && j < wp2.size())
        {
            min_distance = min(min_distance, abs(wp1[i] - wp2[j]));
            if(wp1[i] < wp2[j])
                ++i;
            else
                ++j;
        }
        return min_distance;
    }
    
private:
    unordered_map<string, vector<int>> container;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
 
 /*
 conclusion: a middle level algorithm issue. Using hash-map to resolve the issue.
 Time Complexity is: O(n)
 Space Complexity is: O(n)
 */
