class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();
        int len = 0;
        int count = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == nums[len])
            {
                if(count == 2)
                    continue;
                else
                    count += 1;
            }
            else
                count = 1;
            len += 1;
            nums[len] = nums[i];
        }
        return len+1;
    }
};

Conclusion:
不是一道难题，设一个count记录下来出现次数，如果已经到达2这个值了，skip，如果没达到，count自增1.

Time Complexity: O(n)
Space Complexity: O(1)

    
 Solution 2:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
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
                if(times < 2)
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
