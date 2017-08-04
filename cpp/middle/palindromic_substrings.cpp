class Solution {
public:
    int countSubstrings(string s) {
        int cnt = s.size();
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));
        for(int i = 0; i < s.size(); ++i)
        {
            dp[i][i] = 1;
            for(int j = 0; j < i; ++j)
            {
                if(s[i] == s[j])
                {
                    if(j+1 >= i-1 || dp[j+1][i-1])
                    {
                        dp[j][i] = 1;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};


Conclusion:
a middle level algorithm issue, not easy, we create a n*n matrix to record the result! 
1.  we initialize the ret is s.size(), because each charactor is a palindrome string.
2.  then if s[i] == s[j], it has two conditions, one is j+1 >= i-1, which means at most 1 charactor between i and j, it definitely a palindrome
string; another condition is used to check dp[j+1][i-1], which means move 1 right step from j and 1 left step from i, if it is panlidrome string,
then s[i,j] is also a panlidrome string.

Time Complexity: O(n^2)
Space Complexity: O(n^2)
