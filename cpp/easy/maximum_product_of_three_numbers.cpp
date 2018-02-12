class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size()-1;
        sort(nums.begin(), nums.end());
        int num1 = nums[n-2]*nums[n-1]*nums[n];
        int num2 = nums[0]*nums[1]*nums[n]; //consider negative numbers case
        return max(num1, num2);
    }
};


Conclusion: an easy level algorithm issue, but we need to consider 3 cases for the input array:
1. all the input numbers are positive number, after sort the input array, the maximum product is: nums[n-2]*nums[n-1]*nums[n]
2. all the input numbers are negative number, after sort the input array, the maximum product is: nums[n-2]*nums[n-1]*nums[n]
3. a part of the input numbers are positive, and the rest is negative, the maximum product is: nums[0]*nums[n-1]*nums[n]

Time Complexity: the system sort algorithm should be the quick sort, which is: O(nlogn)
Space Complexity: O(1)
