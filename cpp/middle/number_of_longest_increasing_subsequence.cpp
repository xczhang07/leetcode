class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int n = nums.size();
        vector<int> len(n, 1);
        vector<int> cnt(n,1);
        int maxlen = 0;
        int ret = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] > nums[j])
                {
                    if(len[i] == len[j]+1)
                        cnt[i] += cnt[j];
                    else if(len[i] < len[j] + 1)
                    {
                        len[i] = len[j]+1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            if(maxlen == len[i])
                ret += cnt[i];
            else if(maxlen < len[i])
            {
                maxlen = len[i];
                ret = cnt[i];
            }
        }
        return ret;
    }
};
