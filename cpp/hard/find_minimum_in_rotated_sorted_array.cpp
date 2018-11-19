class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int i = 0;
        int j = nums.size()-1;
        while(i <= j)
        {
            if(nums[i] < nums[j])
                return nums[i];
            int m = i + (j-i)/2;
            if(nums[i] < nums[m])
                i = m + 1;
            else if(nums[m] == nums[j])
                --j;
            else if(nums[m] == nums[i])
                ++i;
            else
                j = m;
        }
        return nums[i];
    }
};

/*

search the pivot position in rotated sorted array, the number would be duplicated, in this case, we need to skip the duplicate
number.

Time Complexity is: O(logN)
Space Complexity is: O(1)
*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int i = 0;
        int j = nums.size()-1;
        while(i < j && nums[i] == nums[j])
            ++i;
        
        while(i <= j)
        {
            if(nums[i] <= nums[j])
                return nums[i];
            int m = i + (j-i)/2;
            if(nums[i] <= nums[m])
                i = m + 1;
            else
                j = m;
        }
        return nums[i];
    }
};

/*
Solution 2, perform the pre-processing for the input array
*/
