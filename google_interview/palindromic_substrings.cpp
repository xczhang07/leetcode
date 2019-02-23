Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.


Time Complexity is: O(n^2)
Space Complexity is: O(n^2)

class Solution {
public:
    int countSubstrings(string s) {
        /*
        dp[i][j] represents the substring of s in [i,j] range
        */
        int n = s.size();
        if(n < 2)
            return n;
        vector<vector<int>> dp(n, vector<int>(n,0));
        int ret = n;
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
            for(int j = 0; j < i; ++j)
            {
                if(s[i] == s[j])
                {
                    if(i-j <= 2 || dp[j+1][i-1] == 1)
                    {
                        ret++;
                        dp[j][i] = 1;
                    }
                }
            }
        }
        return ret;
    }
};
