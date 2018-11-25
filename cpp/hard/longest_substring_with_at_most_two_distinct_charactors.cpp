class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.size() <= 2)
            return s.size();
        int l = 0;
        int t = 0;
        int maxLen = 0;
        unordered_map<char, int> m;
        while(t < s.size())
        {
            if(m.size() < 2)
            {
                m[s[t]]++;
                maxLen = max(maxLen, t-l+1);
            }
            else
            {
                if(m.find(s[t]) != m.end())
                {
                    m[s[t]]++;
                    maxLen = max(maxLen, t-l+1);
                }
                else
                {
                    while(m.size() >= 2)
                    {
                        m[s[l]]--;
                        if(m[s[l]] == 0)
                        {
                            m.erase(s[l]);
                            l++;
                            break;
                        }
                        l++;
                    }
                    m[s[t]]++;
                    maxLen = max(maxLen, t-l+1);
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
