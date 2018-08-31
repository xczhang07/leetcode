class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1)
            return s.size();
        int maxLen = 0;
        int start = 0;
        unordered_map<char, int> distance;
        for(int i = 0; i < s.size(); ++i)
        {
            if(distance.find(s[i]) != distance.end() && distance[s[i]] > start) // the distance[s[i]] should be large than start, then we can update the new start.
                start = distance[s[i]];
            distance[s[i]] = i+1; // plus one because the distance means the length of the string until i position
            maxLen = max(maxLen, i-start+1); //plus one because of the start idx is 0
        }
        return maxLen;
    }
};


/*
Conclusion:
a middle level algorithm issue, which is not very easy. We have to update the index on the fly.
Time Complexity: O(n)
Space Complexity: O(n)
*/
