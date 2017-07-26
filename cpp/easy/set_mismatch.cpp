class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        if(nums.size() <= 1)
            return ret;
        vector<int> map(n+1, 0);
        for(int i = 0; i < nums.size(); ++i)
        {
            if(map[nums[i]] != 0)
                ret.push_back(nums[i]);
            else
                map[nums[i]] += 1;
        }
        for(int i = 1; i <=n; ++i)
        {
            if(map[i] == 0)
                ret.push_back(i);
        }
        return ret;
    }
};


Conclusion:
Easy algorithm issue.
Time Complexity: O(n)
Space Complexity: O(n)
