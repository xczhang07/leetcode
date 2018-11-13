Given n kind of items with size Ai and value Vi(each item has an infinite number available) and a backpack with size m. What's the maximum value can you put into the backpack?

 Notice
You cannot divide item into small pieces and the total size of items you choose should smaller or equal to m.

Example
Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4], and a backpack with size10. The maximum value is 15.
--------------------- 


Backpack III 是无限背包，表示每一个item可以取无数次。
所以通项定义稍有变化。dp[i][j] 为当前到第i个item，拿到size <= j 的最大价值。所以有最后不取第i个item，dp[i][j] = dp[i-1][j], 取第i个item，由于之前也可以取item i，dp[i][j] = dp[i][j-A[i]] + A[i]

通项公式为：
dp[i][j] = max(dp[i-1][j] + dp[i][j-A[i]] + A[i])


int backPack_III(int m, vector<int>& A, vector<int>& V)
{
	if (A.size() == 0 || m <= 0 || A.size() != V.size())
		return 0;
	int n = A.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (j < A[i - 1])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - A[i - 1]] + V[i - 1]);
		}
	}
	return dp[n][m];
}


/*
Time Complexity is: O(m*n)
Space Complexity is: O(m*n)
*/
