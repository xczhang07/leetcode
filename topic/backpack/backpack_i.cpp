Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack?

Example
If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, we can select [2, 3, 5], so that the max size we can fill this backpack is 10. If the backpack size is 12. we can select [2, 3, 7] so that we can fulfill the backpack.

You function should return the max size we can fill in the given backpack.



Analysis: the classic backpack algorithm issue. we can create an two dimission array dp[m][n].
dp[i][j] represents that until to the ith item, how much weight j, we can place into our backpack bag.
the dynamic transfer function as following:

if j < A[i-1]:
  dp[i][j] = dp[i-1][j]
else:
  dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]]+A[i-1])


class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        int n = A.size();
        if(n == 0)
            return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                if(j < A[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]]+A[i-1]);
            }
        }
        return dp[n][m];
    }
};

Time Complexity is: O(m*n)
Space Complexity is: O(m*n)
