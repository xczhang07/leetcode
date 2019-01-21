In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).

Time Complexity is: O(n)
Space Complexity is: O(n)

according to this issue, we are going to get the 3 non-overlaping subarrays maximum sum.
if we get the middle interval is: [i, i+k-1]
then the left interval should be in the range: [0, i-1]
then the middle interval should be in the range: [i+k, n-1]

in order to guarrente each side we should have enough space for left subarray and right subarray.
we should follow the rule:
i >= k
n-1-(i+k)+1 >= k ==> i<=n-2k
thus, the range of i is: k <= i <= n-2k

we caculate every k subarray's sum and store in a sum array.
left[0..i] represents that from the range [0..i] the max subarray sum at this posistion.

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return {};
        vector<int> ret(3,0);
        vector<int> sum; /* stores every k sum value of the subarray */
        int n = nums.size();
        int s = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            s += nums[i];
            if(i >= k)
                s -= nums[i-k];
            if(i >= k-1)
                sum.push_back(s);
        }
        int best = 0;
        vector<int> left(sum.size(), 0);
        for(int i = 0; i < sum.size(); ++i)
        {
            if(sum[i] > sum[best])
                best = i;
            left[i] = best;
        }
        vector<int> right(sum.size(), 0);
        best = sum.size()-1;
        for(int i = sum.size()-1; i >= 0; --i)
        {
            if(sum[i] > sum[best])
                best = i;
            right[i] = best;
        }
        int max_sum = 0;
        for(int i = k; i <= n-2*k; ++i)
        {
            int tmp_sum = sum[left[i-k]] + sum[i] + sum[right[i+k]];
            if(tmp_sum > max_sum)
            {
                max_sum = tmp_sum;
                ret = {left[i-k], i, right[i+k]};
            }
        }
        return ret;
    }

};
