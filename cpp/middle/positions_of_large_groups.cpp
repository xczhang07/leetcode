class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        if(S.size() < 3)
            return {};
        vector<vector<int>> ret;
        int i = 0;
        while( i < S.size()-1)
        {
            int start = i;
            while(i < S.size()-1 && S[i] == S[i+1])
                ++i;
            if(i-start == 0)
                ++i;
            if(i-start+1 >= 3)
                ret.push_back({start, i});
        }
        return ret;
    }
};

/*
Conclusion: 
an easy level algorithm issue on leetcode.
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
