class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        if(k == 0)
            return 0;
        int product = 1;
        int j = 0;
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            product *= nums[i];
            while(j <= i && product >= k)
            {
                product /= nums[j];
                ++j;
            }
            ret += (i-j+1);
        }
        return ret;
    }
};


/*
Time Complexity is: O(n)
space complexity is: O(1)
*/
