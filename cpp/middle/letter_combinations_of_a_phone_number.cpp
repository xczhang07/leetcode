/*
Time Complexity is: O(3^n) ===> every charactor has 3 options, total, the input contains n charactors.
Space Complexity is: O(n) ===> recursive call open the stack is n.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.size() == 0)
            return ret;
        vector<string> dict(10,"");
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";
        string tmp;
        dfs(ret, digits, tmp, dict, 0);
        return ret;
    }
    
    void dfs(vector<string>& ret, string& digits, string& tmp, vector<string>& dict, int level)
    {
        if(digits.size() == tmp.size())
        {
            ret.push_back(tmp);
            return;
        }
        int idx = digits[level]-'0';
        for(int i = 0; i < dict[idx].size(); ++i)
        {
            tmp.push_back(dict[idx][i]);
            dfs(ret, digits, tmp, dict, level+1);
            tmp.pop_back();
        }
        return;
    }
};
