class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> my_map;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(my_map.find(nums[i]) != my_map.end())
            {
                if(abs(my_map[nums[i]] - i) <= k)
                    return true;
                else
                    my_map[nums[i]] = i; //update the index value
            }
            else
                my_map[nums[i]] = i;
        }
        return false;
    }
};


Conclusion: an easy algorithm issue, using map to map the array element and indix;

Time Complexity: O(n)
Space Complexity: O(n)
