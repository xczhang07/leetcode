class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ret;
        if(nums.size() == 0)
            return "";
        if(nums.size() == 1)
            return to_string(nums[0]);
        if(nums.size() == 2)
            return to_string(nums[0])+"/"+to_string(nums[1]);
        ret = to_string(nums[0])+"/(";
        for(int i = 1; i < nums.size(); ++i)
        {
            ret += to_string(nums[i]);
            if (i != nums.size()-1)
                ret += "/";
        }
        ret += ")";
        return ret;
    }
};


Conclusion:
a middle level algorithm question, actually it is an math question, think about we have a group of input number: [x1,x2,x3,x4,x5,...,xn].
We need to add divide operator into it and makes the result is the largest(we have to keep the input number sequence as original). The maxim
value to add parentheis is to insert it after the 1st number and end with the last number of the array as: x1/(x2/x3/x4/x5/.../xn), which means
x1/x2*x3*x4*x5*x6*...*xn

This is the only solution for all the input vector.


Time complexity:
O(n)
Space complexity:
O(1)
