class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i)
            ret ^= nums[i]^(i+1);
        return ret;
    }
};


Conclusion:
easy!
