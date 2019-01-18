Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

Time Complexity is: O(n^2)
Space Complexity is: O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() < 3)
            return ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; ++i)
        {
            int j = i+1; 
            int k = nums.size()-1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while(j < k && nums[j] == nums[j-1])
                        ++j;
                    while(j < k && nums[k] == nums[k+1])
                        --k;
                }
                else if(sum > 0)
                    --k;
                else
                    ++j;
            }
            while(i < nums.size()-2 && nums[i] == nums[i+1])
                ++i;
        }
        return ret;
    }
};
