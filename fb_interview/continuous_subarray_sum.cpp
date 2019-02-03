Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.

Time Complexity is: O(n)
Space Complexity is: O(n)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return false;
        /* k is 0 case */
        if(k == 0)
        {
            for(int i = 0; i < nums.size()-1; ++i)
            {
                if(nums[i] == 0 && nums[i+1] == 0)
                    return true;
            }
            return false;
        }
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            int rest = sum%k;
            if(!m.count(rest))
                m[rest] = i;
            else
            {
                if(i-m[rest] >= 2)
                    return true;
            }
        }
        return false;
    }
};
