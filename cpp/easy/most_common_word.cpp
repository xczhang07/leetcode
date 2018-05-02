class Solution {
public:
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string ret = "";
        unordered_map<string, int> dict;
        int count = 0;
        // invalidation check
        if(paragraph.size() == 0)
            return ret;
        
        // get each word apperance times and store in the hash map
        for(int i = 0; i < paragraph.size(); )
        {
            string word = "";
            while(i < paragraph.size() && isalpha(paragraph[i]))
            {
                word.push_back(tolower(paragraph[i]));
                ++i;
            }
            while(i < paragraph.size() && !isalpha(paragraph[i]))
                ++i;
            dict[word]++;
        }
        
        // set the banned word apperance time to zero
        for(string banned_word : banned)
            dict[banned_word] = 0;
        
        // caculate the most common word appear in the given paragraph
        for(auto ele : dict)
        {
            if(ele.second > count)
            {
                ret = ele.first;
                count = ele.second;
            }
        }
        return ret;
    }
};


Conclusion: 
a leetcode easy level question, find the most common word in the given paragraph except the banned words.
we use 3-pass to process the input, 
1. the 1st pass caculate each word apperance times in the input paragraph.
2. the 2nd pass will set the banned word apperance to 0. 
3. the 3rd pass caculate the most common word in the rest words

Time Complexity: O(n)
Space Complexity: O(n)
