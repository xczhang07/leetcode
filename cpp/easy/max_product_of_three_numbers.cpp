class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size()-1;
        if(nums[0] >= 0)
            return nums[n-2]*nums[n-1]*nums[n];
        else
            return max(nums[n-2]*nums[n-1]*nums[n], nums[0]*nums[1]*nums[n]);
    }
};


Conclusion:
easy, math algorithm!
Time complexity: O(nlogn)
