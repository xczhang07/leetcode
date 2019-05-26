Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]
Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]
Example 3:

Input: ")("
Output: [""]


Time Complexity is: O(2^(l+r))
Space Complexity is: O(n^(l+r))


class Solution {
public:
    bool isValid(string& s)
    {
        int left = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
                ++left;
            else if(s[i] == ')')
                --left;
            if(left < 0)
                return false;
        }
        return true;
    }
    
    void dfs(vector<string>& ret, string s, int left, int right, int idx)
    {
        if(left == 0 && right == 0)
        {
            if(isValid(s))
            {
                ret.push_back(s);
                return;
            }
        }
        
        for(int i = idx; i < s.size(); ++i)
        {
            if(i != idx && s[i] == s[i-1])
                continue;
            if(s[i] == '(' || s[i] == ')')
            {
                string curr = s;
                curr.erase(i,1);
                if(s[i] == '(' && left > 0)
                    dfs(ret, curr, left-1, right, i);
                else if(s[i] == ')' && right > 0)
                    dfs(ret, curr, left, right-1, i);
            }
        }
        return;
    }
   
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;
        if(s.size() == 0)
        {
            ret.push_back("");
            return ret;
        }
        int left = 0, right = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
                left++;
            else if(s[i] == ')')
            {
                if(left == 0)
                    ++right;
                else
                    --left;
            }
        }
        dfs(ret, s, left, right, 0);
        return ret;
    }
};
