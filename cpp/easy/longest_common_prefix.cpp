class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        string compare;
        if(strs.size() == 0)
            return prefix;
        if(strs.size() == 1)
            return strs[0];
        prefix = strs[0];
        int j = 0;
        for(int i = 1; i < strs.size(); ++i)
        {
            j = 0;
            while(j < prefix.size() && j < strs[i].size())
            {
                if(prefix[j] == strs[i][j])
                {
                    compare.push_back(prefix[j]);
                    ++j;
                }
                else
                    break;
            }
            prefix = compare;
            compare.clear();
        }
        return prefix;
    }
};


Conclusion:
easy algorithm issue.
Time complexity is: O(n*L), L is the lenght of common prefix
Space complexity is: O(1)
