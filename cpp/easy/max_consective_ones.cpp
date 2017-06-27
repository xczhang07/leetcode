class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int max_len = 0;
        int len = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 1)
                ++len;
            if(nums[i] == 0)
            {
                max_len = max(len, max_len);
                len = 0;
            }
        }
        max_len = max(len, max_len);
        return max_len;
    }
};


Conclustion:
easy algorithm issue, do not forget caculate the max_len with len at the end of program, such as the case [1,0,0,1,1,0,1,1,1,0,1,1,1,1,1]
