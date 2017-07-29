class NumArray {
public:
    NumArray(vector<int> nums) {
        sum.push_back(0);
        for(int num: nums)
            sum.push_back(sum.back() + num);
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
    
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
 
 
 Conclusion:
 an easy algorithm issue, we initialize a sum array which index will contains the summary value from nums[0]+nums[1]+...+nums[i].
 eg:
 assume: j >= i
 sum[i] = sum[0]+nums[0]+nums[1]+...+nums[i-1]
 sum[j] = sum[0]+nums[0]+nums[1]+...+nums[i-1]+nums[i]+...+nums[j-1]
 sum[j] - sum[i] = nums[i]+nums[i+1]+...+nums[j-1] (the summary between i to j-1 of nums)
 
 if we want to get the summary between index [i,j] of input array nums, we need to use sum[j+1]-sum[i]
 
 Time Complexity is: O(n)
 Space Complexity is: O(n)
