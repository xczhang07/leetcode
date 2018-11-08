class Solution {
public:
   int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        int ret = 0;
        for(i; i < nums.size()-2; ++i)
        {
            int k = i + 2;
            for(int j = i+1; j < nums.size()-1; ++j)
            {
                if(nums[i] > 0)
                {
                    while(k < nums.size() && (nums[i] + nums[j] > nums[k]))
                        ++k;
                    ret += k-j-1; //minus 1 because of the while loop will increse 1 to over the length of the input nums(the k should)
                }
            }
        }
        return ret;
    }
};


Conclusion：
这道题的题意就是给定一个数组，写一个算法，计算出这个数组里面的数字，能组成多少个三角形。
brute force，简单暴力.

Time Complexity: O(n^3)
Space Complexity: O(1)
   
Solution 2
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        int ret = 0;
        int n = nums.size()-1;
        sort(nums.begin(), nums.end());
        for(int i = n; i >= 2; --i)
        {
            int left = 0;
            int right = i-1;
            while(left < right)
            {
                int sum = nums[left]+nums[right];
                if(sum > nums[i])
                {
                    ret += (right-left);
                    --right;
                }
                else
                    ++left;
            }
        }
        return ret;
    }
};

Time Complexity is: O(n^2)
Space Complexity is: O(1)
