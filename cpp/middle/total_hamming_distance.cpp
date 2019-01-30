class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < 32; ++i)
        {
            int num = 0;
            for(int j = 0; j < nums.size(); ++j)
            {
                if((nums[j] >> i) & 1)
                    num++;
            }
            cnt += num * (n-num);
        }
        return cnt;
    }
    
    
};

/*
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
