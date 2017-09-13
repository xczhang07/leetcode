class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int ret = 1;
        int cnt = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i-1]) 
                cnt++;
            else
                cnt = 1;
            ret = max(ret, cnt);
        }
        return ret;
    }
};


Conclusion:
很简单的一道题，每两个相邻的比较大小即可.

Time Complexity: O(n)
Space Complexity: O(1)
