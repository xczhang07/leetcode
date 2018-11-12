class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if(s.size() == 0)
            return ret;
        vector<string> curr;
        dfs(ret, curr, 0 ,s);
        return ret;
    }
    
    
    void dfs(vector<vector<string>>& ret, vector<string>& curr, int start, string& s)
    {
        if(start == s.size())
        {
            ret.push_back(curr);
            return;
        }
        for(int i = start; i < s.size(); ++i)
        {
            if(isPalindrome(s, start, i))
            {
                curr.push_back(s.substr(start, i-start+1));
                dfs(ret, curr, i+1, s);
                curr.pop_back();
            }
        }
        return;
    }
    
    bool isPalindrome(string& s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] == s[end])
            {
                ++start;
                --end;
            }
            else
                return false;
        }
        return true;
    }
};
