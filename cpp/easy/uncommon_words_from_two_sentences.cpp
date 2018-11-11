class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        string combine;
        if(A.size() == 0)
            combine = B;
        else if(B.size() == 0)
            combine = A;
        else
            combine = A + " " + B + " ";
        int st = 0;
        int t = 0;
        unordered_map<string, int> m;
        vector<string> ret;
        while(t < combine.size())
        {
            if(combine[t] == ' ')
            {
                string sub = combine.substr(st, t-st);
                m[sub]++;
                st = t+1;
            }
            ++t;
        }
        for(auto e : m)
        {
            if(e.second == 1)
                ret.push_back(e.first);
        }
        return ret;
    }
};

/*
an easy level algorithm issue, we can combine the two input string as well...
Time Complexity is: O(m+n)
Space Complexity is: O(m+n)
*/
