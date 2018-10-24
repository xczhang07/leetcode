class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = 0;
        for(int num : nums) sum += num;
        vector<bool> visited(nums.size(), false);
        if(sum % k != 0) return false;
        return dfs(nums, k, sum/k, 0, 0, visited);
    }
    
    bool dfs(vector<int>& nums, int k, int target, int start, int currSum, vector<bool>& visited)
    {
        if(k == 1) return true;
        if(target == currSum)
            return dfs(nums, k-1, target, 0, 0, visited);
        for(int i = start; i < nums.size(); ++i)
        {
            if(!visited[i])
            {
                visited[i] = true;
                if(dfs(nums, k, target, i+1, currSum+nums[i], visited)) return true;
                visited[i] = false;
            }
        }
        return false;
    }
};

/*
the solution is the same as combination sum.
Time Complexity is: O(2^n)
Space Complexity is: O(n)

*/
