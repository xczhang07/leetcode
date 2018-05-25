class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
       if(nums.size() <= 1)
           return true;
        int cnt = 0;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            if(nums[i] > nums[i+1])
            {
                if(i == 0|| nums[i-1] <= nums[i+1])
                    nums[i] = nums[i+1];
                else
                    nums[i+1] = nums[i];
                ++cnt;
                if(cnt == 2)
                    return false;
            }
        }
        return true;
    }
};


Conclusion:
一道简单难度的问题，其实就是贪心算法，如果遇见nums[i] > nums[i+1], 要考虑一下nums[i-1]是否也要大于nums[i+1]在i>0的情况下。在建立一个计数器，
如果计数器的值大于等于2，也就是说明这个array没有办法改成non-decreasing array

Time Complexity: O(n)
Space Complexity: O(1)

Second solustion:
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return true;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            if(nums[i] > nums[i+1])
            {
                int temp = nums[i];
                /* remove nums[i] */
                nums[i] = nums[i+1];
                if(is_sorted(nums.begin(), nums.end()))
                    return true;
                /* erase nums[i+1] */
                nums[i] = nums[i+1] = temp;
                if(is_sorted(nums.begin(), nums.end()))
                    return true;
                return false;
            }
        }
        return true;
    }
};


using c++ is_sorted function to resolve this issue.
