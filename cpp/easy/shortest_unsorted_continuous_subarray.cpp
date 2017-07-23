class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        int start = -1;
        int len = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            int j = 0;
            if(nums[i] < nums[i-1])
            {
                j = i;
                while(j > 0 && nums[j] < nums[j-1])
                {
                    swap(nums[j], nums[j-1]);
                    j--;
                }
                if(start == -1 || start > j)
                    start = j;
                len = max(len, i -start + 1);
            }
            
        }
        return len;
    }
};

Conclusion:
compare every two adjacent element in the array nums[i] and nums[i-1], if nums[i-1] > nums[i], then swap the two elements, shift the 
large elements until it is less than the larger value. Them recaculate the len with i-start+1.
Time Complexity: O(n2) worst case
Space Complexity: O(1)
