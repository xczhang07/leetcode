class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
        in this issue, we can maintain two arrays, one stores the max value of subarray product at index i, 
        another array stores the min value of subarray product at index i.
        then after each run, we cacualte the max value.
        time complexity is: O(n)
        space complexity is: O(n)
        */
        int ret = nums[0];
        int n = nums.size();
        vector<int> max_arr(n, 0);
        vector<int> min_arr(n, 0);
        max_arr[0] = nums[0];
        min_arr[0] = nums[0];
        for(int i = 1; i < n; ++i)
        {
            max_arr[i] = max(max(max_arr[i-1]*nums[i], min_arr[i-1]*nums[i]), nums[i]);
            min_arr[i] = min(min(max_arr[i-1]*nums[i], min_arr[i-1]*nums[i]), nums[i]);
            ret = max(ret, max_arr[i]);
        }
        return ret;
    }
};
