/*
According to leetcode question:
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

which requires to remove the duplicates from sorted array, and the duplicates can keep in array at most how many times.
above question is to keep 1 time and 2 times, in this case, we have a general solution(keep the duplicates at most k times)
following solution is to resolve keep duplicates at most k times.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums, int k) {
        if(nums.size() <= 1)
            return nums.size();
        int len = 0;
        int t = 0;
        int num = nums[0];
        int times = 1;
        for(t = 1; t < nums.size(); ++t)
        {
            if(nums[t] == num)
            {
                if(times < k)
                {
                    len++;
                    nums[len] = nums[t];
                }
                times++;   
            }
            else
            {
                nums[++len] = nums[t];
                times = 1;
                num = nums[t];
            }
        }
        return len+1;
    }
};
