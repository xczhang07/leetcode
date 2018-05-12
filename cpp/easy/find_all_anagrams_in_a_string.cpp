class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if(s.size() < p.size())
            return ret;
        /* sliding window */
        vector<int> smap(256, 0), pmap(256, 0);
        for(int i = 0; i < p.size(); ++i)
        {
            smap[s[i]]++;
            pmap[p[i]]++;
        }
        if(smap == pmap)
            ret.push_back(0);
        for(int i = p.size(); i < s.size(); ++i)
        {
            ++smap[s[i]];
            --smap[s[i-p.size()]];
            if(smap == pmap)
                ret.push_back(i-p.size()+1);
        }
        return ret;
    }

};

Conclusion: an easy algorithm of leetcode, using sliding window + two hashmaps

Time Complexity: O(n)
Space Complexity: O(1)


