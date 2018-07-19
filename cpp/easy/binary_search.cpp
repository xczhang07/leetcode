class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};


Conclusion: 
an easy algorithm issue, time complexity is: O(lgn), space complexity is: O(1)
