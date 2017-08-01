class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() <= 1)
            return;
        if(k > nums.size())
           k = k % nums.size();
        reverse_array(nums,0,nums.size()-1);
        reverse_array(nums,0, k-1);
        reverse_array(nums,k,nums.size()-1);
        return;
    }
    
    void reverse_array(vector<int>& nums, int start, int end)
    {
        if(start >= end)
            return;
        while(start < end)
        {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            ++start;
            --end;
        }
        return;
    }
};

Conclusion:
This is an easy algorithm issue. 
first of all, we reverse the whole array; then we reverse the first kth elements; after that, reverse the rest n-k elements of the array.
Time Complexity: O(n)
Space Complexity: O(1)
