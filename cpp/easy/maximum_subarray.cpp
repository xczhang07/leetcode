class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int max_sum = INT_MIN;
        int curr_sum = 0;
        for(int num : nums)
        {
            curr_sum = max(curr_sum+num, num);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};

Conclusion:
an easy algorithm issue, time complexity is： O(n)
