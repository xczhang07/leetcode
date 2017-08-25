class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int max_len = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            int j = i;
            int local_len = 0;
            while(nums[j] >= 0)
            {
                ++local_len;
                int new_idx = nums[j];
                nums[j] = -1;
                j = new_idx;
            }
            max_len = max(max_len, local_len);
        }
        return max_len;
    }
};

Conclusion:
a middle level algorithm issue, it like to find a loop in the array by its value.
we can start from index 0, then we find one by one, when we visit one, then set its value to -1 (because all the elements value between
0 and N), which means the next time we visit this node, we can know a loop find out, and we can update longest length of the circle.

Time Complexity: O(n)
Space Complexity: O(1)
