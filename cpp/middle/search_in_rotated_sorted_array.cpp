class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int start = 0;
        int end = nums.size()-1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
                return mid;
            /* if the begin to mid is sorted */
            if(nums[start] <= nums[mid])
            {
                if(target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            /* if the mid to end is sorted */
            if(nums[mid] <= nums[end])
            {
                if(target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};


/*
Conclusion:
an middle level algorithm issue, search element in rotated sorted array.
time complexity is: O(logn)
space complexity: O(1)
*/
