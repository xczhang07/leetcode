class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            if(i%2 == 0 && nums[i] > nums[i+1])
                swap(nums[i], nums[i+1]);
            else if(i%2 != 0 && nums[i] < nums[i+1])
                swap(nums[i], nums[i+1]);
        }
        return;
        
    }
};

Time Complexity is: O(n)
Space Complexity is: O(1)
