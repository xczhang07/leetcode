class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
    
   
};

/*
Dynamic Programming solution.
Time Complexity is: O(n^2)
Space Complexity: O(n)
*/

// nlog(n) solution with binary search

class Solution {
public:
    int binarySearch(vector<int>& nums, int num) {
        int l = 0;
        int r = nums.size()-1;
        int idx = 0;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(nums[m] == num) {
                return m;
            } else if(nums[m] > num) {
                idx = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return idx;
    }

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.size();
        }
        vector<int> ret;
        for(int num: nums) {
            if(ret.empty() or ret.back() < num) {
                ret.push_back(num);
            } else {
                int idx = binarySearch(ret, num);
                ret[idx] = num;
            }
        }
        return ret.size();
    }
};
