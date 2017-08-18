leetcode 中， 关于 Single Number 的问题有3个， "Single Number", "Single Number ii", 和"Single Number iii"

Single Number：Given an array of integers, every element appears twice except for one. Find that single one.
Single Number ii： Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
Single Number iii：Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

对于第一个问题，运用bit运算中的 异或（XOR）就可以得出答案，因为两个相同数字的异或值为0，所以到最后的结果就是所要求出的那个数值。
第一个问题的解法如下：
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i)
            ret = ret ^ nums[i];
        return ret;
    }
};

对于第二个问题，其实是第一个问题的拓展，也就是说给定的这个数组，除了所要求的那个数字，剩下的数字每个可以出现三次，这样的话，就没有办法运用第一个问题的解法来求解第二个问题了。
这时候，我们应该注意到，整数是4 bytes的，也就是说，整数是32bits。对于这个问题，我们可以计算在每一个bit上1的个数，之后除3取余数，再把每一位上算出的余数组合起来，
就是所要求出的数字。

具体解法如下：
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

通过上述解法，我们可以看出，这个解法是通用的，不光针对出现三次，其实可以复用到每个数字出现n次的情况，于是我们可以得到这样一个general的解法：
int getSingleNumber(vector<int> nums, int appear_times)
{
    int ret = 0;
    if(nums.size() == 0)
        return ret;
    int bit_sum = 0;
    for(int i = 0; i < 32; ++i)
    {
        bit_sum = 0;
        for(int j = 0; j < nums.size(); ++j)
            bit_sum += ((nums[j]>>i)&1);
        bit_sum = bit_sum % appear_times;
        ret = ret | (bit_sum << i);
    }
    return ret;
}

这个想法很棒，可以运用到这一类问题上！

第三个问题，其实也是第一个问题的拓展。给定数组中，只有两个数字是出现一次的，剩下数字均出现两次，这样我们对整个数组的元素进行异或运算，得到的答案是所要求
的那两个数字的异或值，因为这是两个不同的数字，所以异或值肯定是不为0的，这样的话，我们就要求出最低位不为0的那个数值就好，可以运用 mask=num&(~(num-1)) 来求出
这个数值。这个数值，就可以将整个数组分为两个sub-array，一个包含所要求的num1，另一个包含所要求的num2.划分方法为 mask&num == 0 和 mask&num ！= 0 来划分。
这时候针对每个子数组在进行异或运算，就可以求出这两个数字了。具体解法如下：

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
    }
    }
};

这类题主要就是运用了位运算中的异或运算，并且要求对mask有一些的了解。是个很好的总结。
