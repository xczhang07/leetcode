class Solution {
public:
     bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size())
            return false;
         
         unordered_map<string, string> parents;
         string word1;
         string word2;
         for(auto pair : pairs)
         {
             word1 = pair.first;
             word2 = pair.second;
             string parent1 = find(parents, word1);
             string parent2 = find(parents, word2);
             if(parent1 != parent2)
                 parents[parent1] = parent2;  //this step called union, which makes two words have one common parent
         }
         
         for(int i = 0; i < words1.size(); ++i)
         {
             word1 = words1[i];
             word2 = words2[i];
             if(word1 != word2 && find(parents, word1) != find(parents, word2)) //if two words is not same or two words' parent is not same, return false
                 return false;
         }
         
         return true;
    }
    
    string find(unordered_map<string, string>& parents, string word)
    {
        /* find the parent of a word */
        if(parents.find(word) == parents.end())
            parents[word] = word; // the default parent of a word is itself.
        
        while(parents[word] != word)    /* the while loop is used to find the root parent of a word */
            word = parents[word];   
        
        return word;
    }
    
    
};


Conclusion: a typical union find algorithm issue. refer link as following:
https://leetcode.com/problems/sentence-similarity-ii/discuss/109752/JavaC++-Clean-Code-with-Explanation
https://github.com/xczhang07/leetcode/blob/master/topic/union_find.cpp


