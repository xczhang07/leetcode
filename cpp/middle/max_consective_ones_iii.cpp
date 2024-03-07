class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0;
        int kCnt = 0;
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                ++kCnt;
            }
            while(kCnt > k) {
                if(nums[j] == 0) {
                    --kCnt;
                }
                ++j;
            }
            ret = max(ret, i-j+1);
        }
        return ret;
    }
};
