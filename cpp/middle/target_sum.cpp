class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        int sum = 0;
        if(nums.size() == 0)
            return count;
        getCount(nums, S, count, 0, sum);
        return count;
    }
    
    void getCount(vector<int>& nums, int& target, int& count, int idx, int sum)
    {
        if(idx == nums.size())
        {
            if(sum == target)
                ++count;
            return;
        }
        getCount(nums, target, count, idx+1, sum+nums[idx]);
        getCount(nums, target, count, idx+1, sum-nums[idx]);
        return;
    }
};


Conclusion:

解法和combination特别相像， dfs。
Time Complexity: O(n^2)
Space Complexity: O(1)
