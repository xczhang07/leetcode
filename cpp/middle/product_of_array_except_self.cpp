class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        if(nums.size() == 0 || nums.size() == 1)
            return ret;
        vector<int> left(nums.size(), 0); //caculate the left elements product at each index i
        vector<int> right(nums.size(), 0); //caculate the right elements product at each index i
        left[0] = 1;
        right[nums.size()-1] = 1;
        int product = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            product = product * nums[i-1];
            left[i] = product;
        }
        product = 1;
        for(int i = nums.size()-2; i >= 0; --i)
        {
            product = product * nums[i+1];
            right[i] = product;
        }
        for(int i = 0; i < nums.size(); ++i)
            ret.push_back(left[i]*right[i]);
        return ret;
    }
};


Conclusion:
这道题给定一个数组，要计算出另一个数组，其中每个元素的值是不包含这个元素，其他所有元素的乘积，比如给定数组为：[2,3,4]=>[12,8,6].
这道题的解法比较巧妙，我们定义两个数组，一个数组记录当前元素所有左边元素的乘积（不包含这个元素）。另一个数组记录当前元素所有右边元素的乘积（不包含这个元素）
最后将这两个数组在每一位上的左边乘积乘以右边乘积，得到的就是答案。

time complexity: O(n)
space complexity: O(n)
