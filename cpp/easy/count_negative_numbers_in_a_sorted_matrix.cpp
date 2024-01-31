class Solution {
public:

    int binarySearch(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(nums[m] >= 0) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return nums.size() - l;
    }

    int countNegatives(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int ret = 0;
        for(auto& nums: grid) {
            ret += binarySearch(nums);
        }
        return ret;
    }
};
