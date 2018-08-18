class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;
        if(s.size() == 0)
        {
            ret.push_back("");
            return ret;
        }
        int left = 0; // the left parentheses needs to be removed
        int right = 0; // the right parentheses needs to be removed
        /* caculate the number of left and right parentheses need to be removed */
        for(char c: s)
        {
            if(c == '(') ++left;
            else if(left == 0 && c == ')') ++right;
            else if(c == ')') --left;
        }
        
        dfs(ret, s, 0, left, right);
        return ret;
    }
    
    bool is_valid(string s)
    {
        if(s.size() == 0) return true;
        int left = 0;
        for(char c : s)
        {
            if(c == '(') left++;
            else if(c == ')') left--;
            if(left < 0) return false;
        }
        return left == 0;
    }
    
    void dfs(vector<string>& ret, string& s, int start, int left, int right)
    {
        string curr;
        if(left == 0 && right == 0 && is_valid(s))
        {
            ret.push_back(s);
            return;
        }
        
        for(int i = start; i < s.size(); ++i)
        {
            if(i > start && s[i-1] == s[i])
                continue;
            if(s[i] == ')') /* we need to remove the right parentheses first, then remove the left ones, the order is important*/
            {
                curr = s;
                curr.erase(i,1);
                if(right > 0)
                    dfs(ret, curr, i, left, right-1);
            }
            else if(s[i] == '(')
            {
                curr = s;
                curr.erase(i,1);
                if(left > 0)
                    dfs(ret, curr, i, left-1, right);
            }
        }
        return;
    }
};

Conclusion:
a hard issue on leetcode, yes, it is really hard.
we address this issue as following steps:
1. 计算给定字符串要移除多少个左括号和右括号。
	1.1. 对于给定字符串，遇到左括号，左括号数目加1.
	1.2. 遇到右括号，如果左括号数目等于0，右括号数目加1.
	1.3. 遇到右括号，如果左括号数目大于0，左括号减1(匹配了一对儿)。
	1.4. 扫了一遍字符串，时间复杂度是O(n)
2. 检验一个字符串是否合法。
	2.1. 对于给定字符串，从左往右扫，遇到左括号，count加1.
	2.2. 遇到右括号，count减1，如果这时候count < 0, 则字符串不合法.
	2.3. 最后比较count是否为0，如果为0，则字符串合法，反之亦然.
3. 对于整个字符串做dfs
	3.1. 先移除右括号，再移除左括号，直到left == 0， right == 0， 并且字符串合法，则这是一种解法.


Time Complexity: O(2^(l+r))
Space Complexity: recursive, O(n)
