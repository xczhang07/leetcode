class Solution {
public:
    
    int searchLeft(vector<int>& nums, int target)
    {
        int ret = -1;
        int l = 0;
        int r = nums.size()-1;
        int m = 0;
        while(l <= r)
        {
            m = l + (r-l)/2;
            if(nums[m] == target)
            {
                if(m > 0 && nums[m-1] == target)
                    r = m - 1;
                else
                    return m;
            }
            else if(nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return ret;
    }
    
    int searchRight(vector<int>& nums, int target)
    {
        int ret = -1;
        int l = 0;
        int r = nums.size()-1;
        int m = 0;
        while(l <= r)
        {
            m = l + (r-l)/2;
            if(nums[m] == target)
            {
                if(m < nums.size()-1 && nums[m+1] == target)
                    l = m + 1;
                else
                    return m;
            }
            else if(nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return ret;
    }
    
     vector<int> searchRange(vector<int>& nums, int target) {
        return {searchLeft(nums, target), searchRight(nums, target)};
    }
};


/*
Time Complexity: O(logN)
Space Complexity: O(1)
*/
