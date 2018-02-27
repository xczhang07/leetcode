class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        int ret = 0;
        unordered_map<int,int> my_map;
        for(int& num : nums)
            my_map[num]++;
        for(int& num : nums)
        {
            if(my_map.find(num-1) != my_map.end())
                ret = max(ret, my_map[num-1]+my_map[num]);
        }
        return ret;
            
    }
};

Conclusion:
an easy level algorithm issue, we created a hash map to store each element's appear times, then find the element-1 value in the hash map.
if it exists, then caculate the maxim length.

Time Complexity: O(n)
Space Complexity: O(n)
