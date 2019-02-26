Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:

Input: ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]] 
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:

Input: ["bat","tab","cat"]
Output: [[0,1],[1,0]] 
Explanation: The palindromes are ["battab","tabbat"]

class Solution {
public:
    bool isPalindrome(string word)
    {
        int i = 0;
        int j = word.size()-1;
        while(i < j)
        {
            if(word[i] == word[j])
            {
                ++i;
                --j;
            }
            else
                return false;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret;
        if(words.size() == 0)
            return ret;
        unordered_map<string,int> m;
        for(int i = 0; i < words.size(); ++i)
        {
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            m[tmp] = i;
        }
        if(m.count(""))
        {
            for(int i = 0; i < words.size(); ++i)
            {
                if(i == m[""])
                    continue;
                if(isPalindrome(words[i]))
                    ret.push_back({m[""], i});   
            }
        }
        
        for(int i = 0; i < words.size(); ++i)
        {
            for(int j = 0; j < words[i].size(); ++j)
            {
                string left = words[i].substr(0,j);
                string right = words[i].substr(j);
                if(m.count(left) && isPalindrome(right) && i != m[left])
                    ret.push_back({i, m[left]});
                if(m.count(right) && isPalindrome(left) && i != m[right])
                    ret.push_back({m[right], i});
            }
        }
        
        return ret;
    }
};
