class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size() < ransomNote.size())
            return false;
        unordered_map<char, int> my_map;
        for(char c: magazine)
            my_map[c]++;
        for(char c: ransomNote)
        {
            if(my_map[c] > 0)
                --my_map[c];
            else
                return false;
        }
        return true;
    }
};

Conclusion:
easy algorithm issue, use unordered_map can solve this issue.
