Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?


Time Complexity is: O(n^2)
Space Complexity is: O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int n = nums.size();
        vector<int> dp(n, 1);
        int lis = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            lis = max(lis, dp[i]);
        }
        return lis;
    }
    
   
};
