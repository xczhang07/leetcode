class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        if(nums.size() == 0)
            return ret;
        for(int i = 0; i < nums.size(); ++i)
        {
            int idx = abs(nums[i])-1;
            if(nums[idx] < 0)
                ret.push_back(idx+1);
            else
                nums[idx] = -nums[idx];
        }
        return ret;
    }
};


Conclusion:
a middle level algorithm issue, we need to think about the input value range between [1,n]. In this case, we set the nums[nums[i]-1] to negative
value, then check it, if it is already negative value, it means nums[i] appear twice, if not, set it to negative.

Time Complexity: O(n)
Space Complexity: O(1)
