class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return false;
        if(nums.size() == 1)
            return false;
        unordered_set<int> s;
        int sum = 0;
        int pre = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            int mod = (k == 0)?sum : sum%k;
            if(s.count(mod))
                return true;
            else
            {
                s.insert(pre);
                pre = mod;
            }
        }
        return false;
    }
};

/*
if a mod k left c, b mod k left c, then a-b can be divided by k.
a = k*m + c, b = k*n + c. ==> a-b = (m-n)*k.
1. if the k is 0, we need to handle this situation.
2. we have to use another variable pre to keep the previously value, because the continusous subarray's length is at least 2.


Time Complexity is: O(n)
Space Complexity is: O(n)
*/
