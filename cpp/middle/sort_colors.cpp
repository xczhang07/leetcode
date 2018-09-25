class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int travel = left;
        while(travel <= right)
        {
            if(nums[travel] == 0)
            {
                swap(nums[travel], nums[left]);
                ++left;
                ++travel;
            }
            else if(nums[travel] == 2)
            {
                swap(nums[travel], nums[right]);
                --right;
            }
            else
                ++travel;
        }
        return;
    }
};

/*
Conclusion:
an medium algorithm issue, we can use two pointers to travel the whole array and sort the colors.

Time Complexity: O(n)
Space Complexity: O(1)
*/
