class Solution {
public:
    int scoreOfParentheses(string S) {
        int ret = 0;
        int lvl = 0;
        for(int i = 0; i < S.size()-1; ++i)
        {
            if(S[i] == '(')
            {
                if(S[i+1] == ')')
                    ret += 1 << lvl;
                ++lvl;
            }
            else
                --lvl;
        }
        return ret;
    }
};

/*
a middle level algorithm issue, we can caculate the level of each valid "()".
Time Complexity: O(n)
Space Complexity: O(1)
*/
