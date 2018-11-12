class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = 0;
        int last = 0;
        int n = nums.size();
        int ret = 0;
        for(int i = 0; i < n-1; ++i)
        {
            curr = max(curr, i+nums[i]);
            if(last == i)
            {
                last = curr;
                ++ret;
                if(curr >= n-1)
                    break;
            }
        }
        return ret;
    }
};

/*
Greedy Algorithm.
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
