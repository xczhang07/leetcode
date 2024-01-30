class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        if(nums.size() <= 1) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        int pairs = 0;
        while(i < j) {
            int sum = nums[i]+nums[j];
            if(sum < target) {
                pairs += (j - i);
                ++i;
            } else {
                --j;
            }
        }
        return pairs;
    }
};

Time Complexity : O(nlogn) + O(n) => O(nlogn)
Space Complexity : O(1)
