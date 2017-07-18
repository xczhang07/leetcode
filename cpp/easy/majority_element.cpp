class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
        int ret = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(ret == nums[i])
                ++count;
            else
            {
                --count;
                if(count == 0)
                {
                    ret = nums[i];
                    count = 1;
                }
            }
        }
        return ret;
    }
};


Conclusion:
because the majority element's apperance count is greater than n/2; thus, we just need to go through the list, and plus 1 if we met the same
value number, otherwise, minus count number.

Time Complexity is: O(n)
Space Complexity is: O(1)
