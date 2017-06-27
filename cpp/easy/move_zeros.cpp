class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        int curr = 0;
        int tmp = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 0)
            {
                tmp = nums[i];
                nums[i] = nums[curr];
                nums[curr] = tmp;
                ++curr;
            }
        }
    }
};

Conclusion:

easy issue: no extra comments.

time complexity: O(n)
space complexity: O(1)
