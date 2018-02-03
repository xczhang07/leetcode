class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; ++i)
        {
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};



Conclusion: very easy algorithm issue, sort the array, and return ture if two adjacent element is equal; otherwise, return false.

Time Complexity: O(nlogn)
Space Complexity: O(1)
