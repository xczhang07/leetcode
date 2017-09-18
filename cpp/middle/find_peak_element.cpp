int findPeakElement(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
        if(nums.size() == 1)
            return 0;
        int start = 0;
        int end = nums.size()-1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if((mid == 0 && nums[mid] > nums[mid+1]) || (mid == nums.size()-1 && nums[mid] > nums[mid-1]))
                return mid;
            else if((mid > 0 && mid < nums.size()-1) && (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]))
                return mid;
            else if(mid == 0 && nums[mid] < nums[mid+1])
                start = mid+1;
            else if(mid == nums.size()-1 && nums[mid] < nums[mid-1])
                end = mid-1;
            else if(nums[mid+1] > nums[mid])
                start = mid+1;
            else
                end = mid-1;
        }
        return nums[start] > nums[end]? start:end;
    }
    
    
    Conclusion:
    典型的二分查找，corner case比较多,需要考虑的地方比较多。
    
    
    Time Complexity: O(logn)
    Space Complexity: O(1)
