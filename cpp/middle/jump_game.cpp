class Solution {
public:
    bool canJump(vector<int>& nums) {
        /* greedy algorithm */
        int reach = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(i > reach || reach >= n-1)
                break;
            reach = max(reach, i+nums[i]);
        }
        if(reach >= n-1)
            return true;
        else
            return false;
    }
};

/*
Conclusion: for this issue, we use greedy algorithm to resolve it.
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
