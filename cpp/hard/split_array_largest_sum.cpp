class Solution {
public:
    
    bool canSplit(vector<int>& nums, long& target, int& m)
    {
        int total = 0;
        int cnt = 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            total += nums[i];
            if(total > target)
            {
                total = nums[i];
                cnt++;
                if(cnt > m)
                    return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        if(nums.size() == 0)
            return 0;
        long sum = 0;
        int max_num = nums[0];
        for(int i = 0; i < nums.size(); ++i)
        {
            max_num = max(max_num, nums[i]);
            sum += nums[i];
        }
        
        if(m == 1)
            return sum;
        if(m == nums.size())
            return max_num;
        
        long l = max_num;
        long r = sum;
        
        while(l <= r)
        {
            long mid = l+(r-l)/2;
            if(canSplit(nums, mid, m))
                r = mid-1;
            else
                l = mid+1;
        }
        
        return l;
        
    }
    
    
};


Time Complexity is: O(nlogn)
