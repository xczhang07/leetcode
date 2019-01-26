class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() <= 1)
            return ratings.size();
        int ret = 0;
        vector<int> nums(ratings.size(),1);
        for(int i = 0; i < ratings.size()-1; ++i)
        {
            if(ratings[i+1] > ratings[i])
                nums[i+1] = nums[i]+1;
        }
        for(int i = ratings.size()-1; i > 0; --i)
        {
            if(ratings[i-1] > ratings[i])
            {
                if(nums[i-1] <= nums[i])
                    nums[i-1] = nums[i]+1;
            }
        }
        
        for(int num : nums)
            ret += num;
        return ret;
    }
};

/*
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
