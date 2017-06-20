class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        if(nums.size() == 0)
            return ret;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i)
        {
            int rest = target - nums[i];
            if(map.find(rest) != map.end())
            {
                int idx1 = i;
                int idx2 = map[rest];
                ret.push_back(idx1);
                ret.push_back(idx2);
                return ret;
            }
            else
                map[nums[i]] = i;
        }
    }
};

Conclusion:
easy! hashtable!
time complexity: O(n)
space complexity: O(n)
