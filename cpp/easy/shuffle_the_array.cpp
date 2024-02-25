class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuffle_num;
        int i = 0; int j = n;
        while(i < n) {
            shuffle_num.push_back(nums[i]);
            shuffle_num.push_back(nums[j]);
            ++i;
            ++j;
        }
        return shuffle_num;
    }
};
