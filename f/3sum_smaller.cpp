Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Example:

Input: nums = [-2,0,1,3], and target = 2
Output: 2 
Explanation: Because there are two triplets which sums are less than 2:
             [-2,0,1]
             [-2,0,3]
Follow up: Could you solve it in O(n2) runtime?

Time Complexity is: O(n^2)
Space Complexity is: O(1)

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ret = 0;
        if(nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        for(int i = nums.size()-1; i >= 2; --i)
        {
            int j = 0;
            int k = i-1;
            while(j < k)
            {
                int sum = nums[j] + nums[k] + nums[i];
                if(sum < target)
                {
                    ret += (k-j);
                    ++j;
                }
                else
                    --k;
            }
        }
        return ret;
    }
};
