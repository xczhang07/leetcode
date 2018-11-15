class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if(nums.size() == 0)
            return ret;
        int i = 0; 
        int start = 0;
        for(i; i < nums.size(); ++i)
        {
            if(i == nums.size()-1||(long long)nums[i+1]-nums[i] > 1 )
            {
                if(start == i)
                    ret.push_back(to_string(nums[start]));
                else
                    ret.push_back(to_string(nums[start]) + "->"+to_string(nums[i]));
                start = i+1;
            }
        }
        return ret;
    }
};


/*
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
