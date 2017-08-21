class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size()-1;
        int ret = 0;
        while(i < j)
        {
            ret += nums[j] - nums[i];
            ++i;
            --j;
        }
        return ret;
    }
};


Conclusion:

a middle level algorithm issue, we just need to sort the array and caculate the difference bettwen the latest one and the first one, then move
and caculate...


Time Complexity: O(lgN)
Space Complexity: O(1)
