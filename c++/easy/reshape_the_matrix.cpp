class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size() == 0)
            return nums;
        int old_r = nums.size();
        int old_c = nums[0].size();
        int ele_num = old_r * old_c;
        if(r * c > ele_num)
            return nums;
        vector<vector<int>> ret(r, vector<int>(c,0));
        for(int i = 0; i < ele_num; ++i)
            ret[i/c][i%c] = nums[i/old_c][i%old_c];
        return ret;
    }
};
