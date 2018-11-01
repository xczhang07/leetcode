class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-2; i >= 0; --i)
        {
            if(nums[i+1] > nums[i])
            {
                int j = 0;
                for(j = n-1; j > i; --j)
                {
                    if(nums[j] > nums[i])
                        break;
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};

/*
a middle level algorithm issue, for permutation sequence change, we need to understand the rule, a good article as following:
http://www.cnblogs.com/grandyang/p/4428207.html

Time Complexity is: O(n)
Space Complexity is: O(1)
*/
