class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return -1;
        sort(nums.begin(), nums.end());
        int distance = INT_MAX;
        int ret  = 0;
        int i = 0;
        for(int i = 0; i < nums.size()-2; ++i)
        {
            int j = i + 1;
            int k = nums.size()-1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                if(diff == 0)
                    return sum;
                if(diff < distance)
                {
                    distance = diff;
                    ret = sum;
                }
                if(sum > target)
                    --k;
                else
                    ++j;
            }
            
        }
        return ret;
    }
};

/*
Conclusion: a middle level algorithm issue on leetcode, very similiar with 3sum and 3sum smaller, same work out solution.
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
