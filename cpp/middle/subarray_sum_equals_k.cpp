class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        int ret = 0;
        int sum = 0;
        unordered_map<int, int> map;
        for(auto num : nums)
        {
            map[sum] += 1;
            sum += num;
            ret += map[sum-k];
        }
        return ret;
    }
};


Conclusion:
一道middle level的问题，刚开始接触的时候，感觉挺简单，但后来发现不是很简单。
其实是一道dp的问题。建立一个哈希表，对于每一个subarray的sum进行存储，存储这个值出现了多少次，如果对于sum-k存在，则说明，sum to k也是存在的
Time Complexity：O（n）
Space Complexity： O（n）
