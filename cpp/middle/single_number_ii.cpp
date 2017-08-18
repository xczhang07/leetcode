class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        if(nums.size() == 0)
            return ret;
        int sum = 0;
        for(int i = 0; i < 32; ++i)
        {
            sum = 0;
            for(int j = 0; j < nums.size(); ++j)
            {
                int bit_val = (nums[j] >> i) & 1;
                sum += bit_val;
            }
            sum %= 3;
            ret |= (sum << i);
        }
        return ret;
    }
};


Conclusion:
an middle level algorithm question. Given an input array, all the numbers appear 3 times except only 1 number appear 1 time, our goal is to
find out the one which only appear 1 time in the input array.
In this case, because integer number is 4 bytes=>32 bits; then we can caculate each position (0 ~ 31) how many 1 on each bit, then divide by 3
(because the other number all appear 3 times in the input array.) then we organize each bit number to get the result.

time complexity: O(32N) => O(N)
space complexity: O(1)
