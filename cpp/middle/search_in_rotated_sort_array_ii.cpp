class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /* worst case time complexity is: O(n) */
        if(nums.size() == 0)
            return false;
        int start = 0;
        int end = nums.size()-1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] == nums[start] && nums[mid] == nums[end]) /* the only difference between rotated search I, tricky part */
            {
                start++;
                end--;
            }
            else if(nums[start] <= nums[mid])
            {
                if(nums[start] <= target && nums[mid] > target)
                    end = mid-1;
                else
                    start = mid+1;
            }
            else if(nums[mid] <= nums[end])
            {
                if(nums[mid] < target && nums[end] >= target)
                    start = mid+1;
                else
                    end = mid-1;
            }
        }
        return false;
    }
};

/*
Conclusion:
a middle level algorithm issue, time complexity is: O(logN), worst case is: O(n)
the extension of search in rotated sorted array i, contains duplicate number.
*/
