class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        int begin = 0;
        int end = nums.size()-1;
        while(begin <= end)
        {
            int mid = begin + (end-begin)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                begin = mid+1;
            else
                end = mid-1;
        }
        return begin;
    }
};

Conclusion:
Easy issue, binary search, time complexity is: O(logN), N is the number of elements in the input array. Space Complexity is: O(1)
