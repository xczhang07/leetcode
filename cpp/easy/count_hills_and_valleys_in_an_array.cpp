class Solution {
public:
    int countHillValley(vector<int>& nums) {
        if(nums.size()  < 3) {
            return 0;
        }
        int ret = 0;
        int i = 1;
        for(int i = 1; i <= nums.size()-2; ++i) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                ret++;
            } else if (nums[i] < nums[i-1] && nums[i] < nums[i+1]){
                ret++;
            } else {
                if(nums[i] > nums[i-1] && nums[i] == nums[i+1]) {
                    int j = i+1;
                    while(j < nums.size()-1 && nums[j] == nums[j-1]) {
                        ++j;
                    }
                    if(nums[i] > nums[j]) {
                        ++ret; // detects a hill. 
                    } 
                    i = j-1;      
                } else if(nums[i] < nums[i-1] && nums[i] == nums[i+1]) {
                    int j = i+1;
                    while(j < nums.size()-1 && nums[j] == nums[j-1]) {
                        ++j;
                    }
                    if(nums[i] < nums[j]) {
                        ++ret; // detects a valley.
                    }
                    i = j-1;
                }
            }
        }
        return ret;
    }
};
