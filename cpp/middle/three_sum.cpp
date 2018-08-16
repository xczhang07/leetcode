class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() < 3)
            return ret;
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size()-2; ++i)
        {
            while(i > 0 && nums[i] == nums[i-1]) // pruning
                ++i;
            int j = i+1;
            int k = nums.size()-1;
            while(j < k)
            {
                sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    ret.push_back(tmp);
                    ++j;
                    --k;
                    while(nums[j] == nums[j-1]) // pruning
                        ++j;
                    while(nums[k] == nums[k+1]) // pruning
                        --k;
                }
                else if(sum < 0)
                    ++j;
                else
                    --k;
            }
        }
        return ret;
    }
};

Conclustion: an middle level algorithm, we need to pruning in the code to reduce the time complexity. 
Time Complexity is: O(n^2)
Space Complexity is: O(n^2)
