class Solution {
public:
    /* 
    time complexity is: O(n) 
    space complexity is: O(n) 
    */
    bool checkInclusion(string s1, string s2) {
        if(s1.size() == 0)
            return true;
        if(s2.size() == 0)
            return true;
        unordered_map<char,int> m;
        int start = 0;
        int len = 0;
        for(int i = 0; i < s1.size(); ++i)
            m[s1[i]]++;
        for(int i = 0; i < s2.size(); ++i)
        {
            m[s2[i]]--;
            if(m[s2[i]] >= 0)
                ++len;
            while(len == s1.size())
            {
                if(i-start+1 == s1.size())
                    return true;
                m[s2[start]]++;
                if(m[s2[start]] > 0)
                    len--;
                ++start;
            }
        }
        return false;
    }
};
