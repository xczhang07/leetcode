class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0)
            return 1;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i])
                swap(nums[i], nums[nums[i]-1]);
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};

/*
Conclusion:
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
