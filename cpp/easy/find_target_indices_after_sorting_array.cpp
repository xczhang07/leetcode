# Binary Search
# Time Complexity: O(NlogN) + O(lgN)
# Space Complexity: O(1)

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return {};
        }
        vector<int> ret;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while(i <= j) {
            int m = i + (j-i)/2;
            if(nums[m] == target) {
                int t = m;
                while(t >= 0 && nums[t] == target) {
                    ret.insert(ret.begin(), t);
                    --t;
                }
                t = m + 1;
                while(t < nums.size() && nums[t] == target) {
                    ret.push_back(t);
                    ++t;
                }
                return ret;
            } else if (nums[m] < target) {
                i = m + 1;
            } else {
                j = m - 1;
            }
        }
        return {};
    }
};
