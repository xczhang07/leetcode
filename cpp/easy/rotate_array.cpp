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

class Solution {
public:
    
    void rotate(vector<int>& nums, int k) {
        if(k == 0 || nums.size() == 0)
            return;
        int t = 0;
        while(t < k)
        {
            int temp = nums[nums.size()-1];
            nums.insert(nums.begin(), temp);
            nums.pop_back();
            t++;
        }
        return;
    }
};

Conclusion: just move the tail element of the array to the front until the operation k times.
Time Complexity: O(k)
Space Complexity: O(1)
