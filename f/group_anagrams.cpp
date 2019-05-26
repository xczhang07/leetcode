Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

class Solution {
public:
    /*
    time complexity is O(n)
    space complexity is O(n)
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if(strs.size() == 0)
            return ret;
        unordered_map<string, vector<string>> m;
        for(string s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(s);
        }
        
        for(auto e : m)
            ret.push_back(e.second);
        return ret;
    }
};
