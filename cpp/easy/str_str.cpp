class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())
            return -1;
        else if(needle.size() == 0 && needle.size() == 0)
            return 0;
        int idx1 = 0;
        int idx2 = 0;
        for(idx1; idx1 < haystack.size(); ++idx1)
        {
            if(haystack[idx1] == needle[idx2])
                ++idx2;
            else
            {
                idx1 = idx1-idx2;
                idx2 = 0;
            }
            if(idx2 == needle.size())
                return idx1-idx2+1;
        }
        return -1;
    }
};

Conclusion: an easy level question of leetcode. 

Time Complexity: O(n)
Space Complexity: O(1)
