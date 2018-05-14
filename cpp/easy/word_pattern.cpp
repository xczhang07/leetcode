class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(pattern.size() == 0 || str.size() == 0)
            return false;
        vector<string> words;
        getWords(str, words);
        unordered_map<char,string> map1;
        unordered_map<string, char> map2;
        if(pattern.size() != words.size())
            return false;
        for(int i = 0; i < pattern.size(); ++i)
        {
            if(map1.find(pattern[i]) == map1.end())
                map1[pattern[i]] = words[i];
            else
                if(map1[pattern[i]] != words[i]) return false;
            
            if(map2.find(words[i]) == map2.end())
                map2[words[i]] = pattern[i];
            else
                if(map2[words[i]] != pattern[i]) return false;
        }
        return true;
    }
    
    void getWords(string str, vector<string>& words)
    {
        int start = 0;
        int end = 0;
        while(end < str.size())
        {
            if(str[end] == ' ')
            {
                words.push_back(str.substr(start, end-start));
                start = end+1;
            }
            ++end;
        }
        /* process the last word */
        words.push_back(str.substr(start, end-start));
        return;
    }
};

Conclusion: an easy algorithm issue, not a big deal, easy! 
which the idea is very similiar with find_all_anagrams_in_a_string issue

Time Complexity: O(n)
Space Complexity: O(n)
