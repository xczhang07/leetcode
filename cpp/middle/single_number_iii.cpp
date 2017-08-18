class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret(2, 0);
        if(nums.size() == 0)
            return ret;
        int xor_val = 0;
        for(int i = 0; i < nums.size(); ++i)
            xor_val ^= nums[i];
        int most_right_one = xor_val & (~(xor_val-1));
        for(int i = 0; i < nums.size(); ++i)
        {
            if((nums[i] & most_right_one ) != 0)
                ret[0] ^= nums[i];
            else
                ret[1] ^= nums[i];
        }
        return ret;
    }
};


Conclusion:
A middle level algorithm issue, given an integer number, except to unique numbers, all the other numbers appear 2 times in the array.
Unlike the question "Single Number", we cannot directly use xor operation to get the two distinguish number; however, we can think about
it and do some extra caculation on it, the following approach would get the two numbers:
1. perform the xor operation in the whole array. (like the "Single Number" case)
2. actually, the result of step 1 is the xor value of the two distinguish number, because they are different; thus the xor value is not 0,
we can use the notation: val & (~(val-1)) to caculate the first different bit position(from right to left) of the two different numbers.
3. after we got the first difference position, we go over the whole array again, we can divide the numbers into two group for sure. 
   group1: num[i] & first_bit_pos == 1
   group2: num[i] & first_bit_pos == 0
   and each group will have odd numbers for sure. And we perform the xor operations for the two groups, then we can get those two distinguish
   values.
   
Time Complexity: O(n)
Space Complexity: O(1)
