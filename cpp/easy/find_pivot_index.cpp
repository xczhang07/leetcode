class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
        long part_sum = 0;
        long sum = get_sum(nums);
        for(int i = 0; i < nums.size(); ++i)
        {
            part_sum += nums[i];
            if((part_sum - nums[i]) == (sum - part_sum))
                return i;
        }
        return -1;
    }
    
    long get_sum(vector<int>& nums)
    {
        long sum = 0;
        for(auto num : nums)
            sum += num;
        return sum;
    }
};


Conclusion: an easy level algorithm of leetcode, mathmatica issue. No comments

Time Complexity: O(n)
Space Complexity: (1)
