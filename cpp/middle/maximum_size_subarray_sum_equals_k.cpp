class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        int sum = 0;
        int max_len = 0;
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if(sum == k)
                max_len = i+1;
            if(m.find(sum - k) != m.end())
                max_len = max(max_len, i-m[sum-k]);
            if(!m.count(sum))
                m[sum] = i;
        }
        return max_len;
    }
};
