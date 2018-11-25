class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0)
            return 0;
        if(s.size() <= 1)
            return s.size();
        if(s.size() <= k)
            return s.size();
        unordered_map<char,int> m;
        int l = 0;
        int t = 0;
        int maxLen = 0;
        while(t < s.size())
        {
            if(m.size() < k)
            {
                m[s[t]]++;
                maxLen = max(maxLen, t-l+1);
            }
            else
            {
                if(m.find(s[t]) != m.end()) {
                    m[s[t]]++;
                    maxLen = max(maxLen, t-l+1);
                }
                else {
                    while(m.size() >= k) {
                        m[s[l]]--;
                        if(m[s[l]] == 0)
                        {
                            m.erase(s[l++]);
                            break;
                        }
                        ++l;
                    }
                    m[s[t]]++;
                }
            }
            ++t;
        }
        return maxLen;
    }
};

/*
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
