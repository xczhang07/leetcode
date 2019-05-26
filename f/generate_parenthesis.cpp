Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]


Time Complexity is: O(2^n)
Space Complexity is: O(n)


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        int left = n;
        int right = n;
        string curr;
        generator(ret, left, right, curr);
        return ret;
    }
    
    void generator(vector<string>& ret, int left, int right, string parenthesis)
    {
        if(left > right)
            return;
        if(left == 0 && right == 0)
        {
            ret.push_back(parenthesis);
            return;
        }
        if(left > 0)
            generator(ret, left-1, right, parenthesis+'(');
        if(right > 0)
            generator(ret, left, right-1, parenthesis+')');
        return;
    }
};
