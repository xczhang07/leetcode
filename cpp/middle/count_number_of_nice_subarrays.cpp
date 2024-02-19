class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int s = 0;
        int e = 0;
        int cnt = 0;
        int ret = 0;
        while(e < nums.size()) {
            if(nums[e]%2 == 1) {
                ++cnt;
                if(cnt == k) {
                   int t = e;
                   while(t < nums.size()-1 && nums[t+1] % 2 == 0) {
                       ++t;
                   }
                   int factor1 = t-e+1;
                   t = s;
                   while(t < e && nums[t]%2 == 0) {
                       ++t;
                   }
                   int factor2 = t-s+1;
                   ret += factor1*factor2;
                   s = t;
                   ++s;
                   --cnt;
                }
            } 
            ++e;
        }
        return ret;
    }
};
