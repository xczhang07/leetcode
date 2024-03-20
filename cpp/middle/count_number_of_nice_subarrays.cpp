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


Using atMost k algorithm to resolve this issue
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }

    int atMost(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int oddCnt = 0;
        int ret = 0;
        while(j < nums.size()) {
            // detect an odd number.
            if(nums[j] % 2 == 1) {
                oddCnt++;
            }
            while(oddCnt > k) {
                if(nums[i]%2 == 1) {
                    --oddCnt;
                }
                ++i;
            }
            ret += j-i+1;
            ++j;
        }
        return ret;
    }
};
