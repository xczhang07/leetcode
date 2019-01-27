class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        /* time complexity is O(nlogn) */
        if(nums.size() == 0)
            return 0;
        vector<int> sums(nums.size()+1, 0);
        int min_len = INT_MAX;
        for(int i = 1; i <= nums.size(); ++i)
            sums[i] = sums[i-1]+nums[i-1];
        for(int i = 0; i < nums.size(); ++i)
        {
            int target = sums[i] + s;
            int l = 0, r = nums.size();
            int m = 0;
            while(l <= r)
            {
                m = (r-l)/2 + l;
                if(sums[m] < target)
                    l = m + 1;
                else
                {
                    if(m > 0 && sums[m-1] >= target)
                        r = m-1;
                    else if(m > 0 && sums[m-1] < target)
                        break;
                    else if(m == 0)
                        break;
                }
            }
            if(sums[m]-sums[i] >= s)
                min_len = min(min_len, m-i);
        }
        return min_len == INT_MAX? 0 : min_len;
    }
};
