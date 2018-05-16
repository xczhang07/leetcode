class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size()-1;
        /* skip all the empty space start from end */
        while(end >= 0 && s[end] == ' ')
            --end;
        int len = 0;
        while(end >= 0 && s[end] != ' ')
        {
            --end;
            ++len;
        }
        return len;
    }
};

Conclusion: an easy issue of leetcode, no comments.

Time Complexity: O(n)

Space Complexity: O(1)
