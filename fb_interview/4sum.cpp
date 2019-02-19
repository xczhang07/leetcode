class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if(nums.size() < 4)
            return ret;
        sort(nums.begin(), nums.end());
        int i = 0;
        for(i = 0; i < nums.size()-3; ++i)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i+1;
            for(j; j < nums.size()-2; ++j)
            {
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int t = j+1;
                int k = nums.size()-1;
                while(t < k)
                {
                    int sum = nums[i] + nums[j] + nums[t] + nums[k];
                    if(sum == target)
                    {
                        ret.push_back({nums[i], nums[j], nums[t], nums[k]});
                        ++t;
                        --k;
                        while(t < k && nums[t] == nums[t-1])
                            ++t;
                        while(t < k && nums[k] == nums[k+1])
                            --k;
                    }
                    else if(sum > target)
                        --k;
                    else
                        ++t;
                }
            }
        }
        return ret;
    }
};
