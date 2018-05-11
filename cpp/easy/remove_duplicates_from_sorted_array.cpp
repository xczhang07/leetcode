class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /* invalidation check */
        if(nums.size() <= 1)
            return nums.size();
        int len = 0;
        int curr = nums[0];
        for(int i = 0; i < nums.size(); ++i)
        {
            if(curr == nums[i]) /* if the curr value equals to the nums[i] value, just skip it */
                continue;
            else    /* update the length and curr value */
            {
                len += 1;
                nums[len] = nums[i];
                curr = nums[i];
            }
        }
        return len+1; /* return length should be the real length of the array, which is len+1 */
    }
};


Conclustion: an easy level algorithm issue on leetcode, no comments

Time Complexity: O(n)
Space Complexity: O(1)
