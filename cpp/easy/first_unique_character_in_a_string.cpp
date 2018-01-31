class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 0)
            return -1;
        unordered_map<char, int> my_map;
        for(char e: s)
            my_map[e]++;
        for(int i = 0; i < s.size(); ++i)
        {
            if(my_map[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

Conclusion:
easy algorithm issue, using hash_map can resolve it. 

Time Complexity: O(n)
Space Complexity: O(n)
