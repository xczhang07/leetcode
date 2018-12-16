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

Solution 2: using sliding window + hash_set to resolve the issue
abcabcbb

1. first round the sliding window is: abc, maxLen is 3.
2. then we find out a already exist in the hash set, we shift the sliding window, now sliding become: bca
3. when we meet some charactor already exist in the hash set, we shift the window: cab
4, sliding window is: abc
5, sliding window is: cb
6, sliding window is: b

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /* maintain a sliding window */
        if(s.size() <= 1)
            return s.size();
        int maxLen = 0;
        int l = 0;
        int r = 0;
        unordered_set<char> visited;
        while(r < s.size())
        {
            if(!visited.count(s[r]))
            {
                maxLen = max(maxLen, r-l+1);
                visited.insert(s[r]);
            }
            else
            {
                while(l != r && s[l] != s[r])
                {
                    visited.erase(s[l]);
                    ++l;
                }
                ++l;
            }
            ++r;
        }
        return maxLen;
    }
};


Solustion 3:
more efficient consistent memory
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         if(s.size() < 2)
             return s.size();
        int start = 0;
        int max_len = 0;
        vector<int> dict(256, 0);
        for(int i = 0; i < s.size(); ++i)
        {
            while(dict[s[i]] == 1)
            {
                dict[s[start]] = 0;
                ++start;
            }
            dict[s[i]] = 1;
            max_len = max(max_len, i-start+1);
        }
        return max_len;
    }
};
