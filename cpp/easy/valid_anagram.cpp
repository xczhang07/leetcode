class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char,int> my_map;
        for(char e: s)
            my_map[e]++;
        for(char e: t)
        {
            if(my_map.find(e) == my_map.end())
                return false;
            else if(my_map[e] == 0)
                return false;
            else
                my_map[e]--;
        }
        return true;
    }
};

Conclusion:
very easy algorithm issue, using hash map can resolve the issue. No comments.

Time Complexity: O(n)
Space Complexity: O(n)
