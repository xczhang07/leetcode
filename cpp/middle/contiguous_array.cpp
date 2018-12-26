class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int,int> m;
        m[0] = -1;
        int sum = 0;
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0) sum -= 1;
            else sum += 1;
            if(m.count(sum))
                ret = max(ret, i-m[sum]);
            else
                m[sum] = i;
        }
        return ret;
    }
};
