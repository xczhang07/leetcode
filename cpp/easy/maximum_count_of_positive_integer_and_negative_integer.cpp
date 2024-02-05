Time Complexity is: O(logN)

class Solution {
public:
    int firstPositive(vector<int>& nums, int i, int j) {
        while(i <= j) {
            int m = i + (j-i)/2;
            if(nums[m] > 0) {
                if(m == 0 || (m > 0 && nums[m-1] <= 0)) {
                    return m;
                } else {
                    j = m - 1;
                }
            } else {
                i = m + 1;
            }
        }
        return j;
    }

    int lastNegative(vector<int>& nums, int i , int j) {
        while(i <= j) {
            int m = i + (j-i)/2;
            if(nums[m] < 0) {
                if(m == nums.size()-1 || (m < nums.size()-1 && nums[m+1] >= 0)) {
                    return m;
                } else {
                    i = m + 1;
                }
            } else {
                j = m - 1;
            }
        }
        return i;
    }

    int maximumCount(vector<int>& nums) {
        // Handle the corner case where all the number is 0.
        int i = 0;
        while(i < nums.size() && nums[i] == 0) {
            ++i;
        }
        if(i == nums.size()) {
            return 0;
        }
        int positive_idx = firstPositive(nums, i, nums.size()-1);
        int positive_num = nums.size()-positive_idx;
        int negative_idx = lastNegative(nums, i, nums.size()-1);
        int negative_num = negative_idx-i+1;
        return max(positive_num, negative_num);
    }
};
