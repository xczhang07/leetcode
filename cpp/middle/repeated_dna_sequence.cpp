class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if(s.size() < 10)
            return ret;
        unordered_map<string, int> freq;
        for(int i = 0; i <= s.size()-10; ++i)
        {
            string dna = s.substr(i, 10);
            freq[dna]++;
        }
        for(auto e : freq)
        {
            if(e.second > 1)
                ret.push_back(e.first);
        }
        return ret;
    }
};


/*
Conclusion:
a middle level algorithm issue, we can use hash_map to resolve it.
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
