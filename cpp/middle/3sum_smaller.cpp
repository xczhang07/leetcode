class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        int ret = 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; ++i)
        {
            l = i+1;
            r = nums.size()-1;
            while(l < r)
            {
                sum = nums[i] + nums[l] + nums[r];
                if(sum < target)
                {
                    ret += (r - l);
                    l++;
                }
                else
                    r--;
            }
        }
        return ret;
    }
};


/*an middle level algorithm issue, same concept with 3sum */
