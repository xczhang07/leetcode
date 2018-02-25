class Solution {
public:
    string longestWord(vector<string>& words) {
        string ret;
        unordered_set<string> dict(words.begin(), words.end());
        
        for(string word : words)
        {
            string prefix;
            bool valid = true;
            if(word.size() < ret.size() || (word.size() == ret.size() && word > ret))  //pruning
                continue;
            for(int i = 0; i < word.size()-1; ++i)
            {
                prefix += word[i];
                if(!dict.count(prefix))  
                {
                    valid = false;
                    break;
                }
            }
            if(valid)
                ret = word;
        }
        return ret;
    }
};

Conclusion: this issue is not as easy as its tag(issue algorithm issue).
this algorithm lets you check whether or not the prefix of the word in the input words string array, then find out the longest one 
with less lexicographical order (eg: apple < apply)

Time Complexity: O(n*w)  n is the word number and w is each word's length.

Space Complexity: O(n*w)
