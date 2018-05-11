class Solution {
public:
    int countSegments(string s) {
        int count = 0, i = 0;
        while(i < s.size())
        {
            while(i < s.size() && s[i] == ' ')
                ++i;
            if(i < s.size() && s[i] != ' ')
                ++count;
            while(i < s.size() && s[i] != ' ')
                ++i;
        }
        return count;
    }
};

Conclusion: an easy algorithm issue on leetcode, no comments

Time Complexity: O(n)
Space Complexity: O(1)
