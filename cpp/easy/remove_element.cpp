class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        int len = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == val)
                continue;
            else
            {
                nums[len] = nums[i];
                ++len;
            }
        }
        return len;
    }
};

Conclusion:
an easy algorithm issue, no comments

Time Complexity: O(n)
Space Complexity: O(1)
