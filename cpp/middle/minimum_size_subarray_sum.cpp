class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int sum = 0;
        int min_len = INT_MAX;
        int start = 0;
        int end = 0;
        while(end < nums.size())
        {
            sum += nums[end];
            if(sum >= s)
                min_len = min(min_len, end-start+1);
            while(sum-nums[start] >= s)
            {
                sum -= nums[start];
                ++start;
                min_len = min(min_len, end-start+1);
            }
            ++end;
        }
        return min_len == INT_MAX? 0 : min_len;
    }
};


/*
Time Complexity is: O(n)
Space Complexity is: O(1)

two pointers
*/
