Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

Seen this question in a real interview before? 

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return;
        vector<int> tmp = nums;
        int n = nums.size();
        sort(tmp.begin(), tmp.end());
        int i = n-1;
        int j = (n-1)/2;
        for(int k = 0; k < n; ++k)
        {
            if(k%2 == 0)
            {
                nums[k] = tmp[j];
                --j;
            }
            else
            {
                nums[k] = tmp[i];
                --i;
            }
        }
        return;
    }
};
