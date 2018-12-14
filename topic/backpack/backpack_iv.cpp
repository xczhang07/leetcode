Given n items with size nums[i] which an integer array and all positive numbers, no duplicates. 
An integer target denotes the size of a backpack. Find the number of possible fill the backpack.
Each item may be chosen unlimited number of times

Example
Given candidate items [2,3,6,7] and target 7,

A solution set is: 
[7]
[2, 2, 3]
return 2


求方案个数，求方案个数就是把取max，变成求和。由于还是无限背包，即每个item可以用无数次，所以还是看同一行。通项公式如下：
dp[i][j] 为取到前i个数，组成size <= j 的总方案个数。
dp[i][j] = dp[i-1][j] + dp[i][j-A[i]];

初始化时，要把起始整个column都设为1.

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        if(nums.size() == 0) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for(int i = 1; i <= n; ++i)
        {
            dp[i][0] = 1;
            for(int j = 1; j <= target; ++j)
            {
                if(j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j]+dp[i][j-nums[i-1]];
            }
        }
        return dp[n][target];
    }
};
