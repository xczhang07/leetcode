class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       if(nums.size() == 0)
           return 0;
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};


Time Complexity: O(n)
Space Complexity: O(1)

    
    class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        Time Complexity is: O(nlogn)
        */
        int l = 1;
        int h = nums.size()-1;
        int cnt = 0;
        while(l <= h)
        {
            cnt = 0;
            int mid = l + (h-l)/2;
            for(auto n : nums)
            {
                if (n <= mid)
                    cnt++;
            }
            if(cnt <= mid)
                l = mid + 1;
            else
                h = mid-1;
        }
        return l;
    }
};

Time Complexity: O(nlogn)
Space Complexity: O(1)
