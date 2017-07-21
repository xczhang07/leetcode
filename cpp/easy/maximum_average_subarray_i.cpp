class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //  for this issue, we create a siliding window!
        //  step1, we caculate the first k numbers summary in the input array, then caculate the average value of the array
        //  step2, from the kth element of the array, add one element and minus one(because the algorithm requests contiguous subarray)
        //         then compare the average of the new sum value with the existing.
        //         we create an k elements siliding windows, just shift the windows from left to right to caculate the maxiam average value
        //         of the contiguous subarray
        if(nums.size() == 0)
            return 0;
        double sum = 0;
        double ret = INT_MIN;
        for(int i = 0; i < k; ++i)
            sum += nums[i];
        ret = max(ret, sum/k);
        for(int i = k; i < nums.size(); ++i)
        {
            sum += (nums[i]-nums[i-k]);
            ret = max(ret, sum/k);
        }
        return ret;
    }
};


Conclusion:

an easy algorithm question, create a k size siliding window to caculate the average value of kth subarray.

Time Complexity is: O(n)
Space Complexity is: O(1)
