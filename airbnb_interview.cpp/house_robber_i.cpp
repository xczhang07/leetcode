class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int n = nums.size();
        vector<int> sums(n, 0);
        sums[0] = nums[0];
        sums[1] = max(nums[0],nums[1]);
        for(int i = 2; i < n; ++i)
        {
            sums[i] = max(sums[i-1], sums[i-2]+nums[i]);
        }
        
        return sums[n-1];
        
    }
};
