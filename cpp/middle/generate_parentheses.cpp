class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n <= 0) return ret;
        string curr;
        int left = n;
        int right = n;
        dfs(ret, curr, left, right);
        return ret;
    }
    
    void dfs(vector<string>& ret, string curr, int left, int right)
    {
        if(left > right)
            return;
        if(left == 0 && right == 0)
        {
            ret.push_back(curr);
            return;
        }
        if(left > 0)
            dfs(ret, curr+'(', left-1, right);
        if(right > 0)
            dfs(ret, curr+')', left, right-1);
        return;
    }
};

/*
an middle level algorithm issue, we can using dfs + backtracking to resolve this issue.
*/
