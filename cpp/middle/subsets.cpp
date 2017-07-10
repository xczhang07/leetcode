class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        if(nums.size() == 0)
        {
            ret.push_back(tmp);
            return ret;
        }
        ret.push_back(tmp);
        int idx = 0;
        dfs(ret, tmp, nums, idx);
        return ret;
    }
    
    void dfs(vector<vector<int>>& ret, vector<int>& tmp, vector<int>& nums, int idx)
    {
        if(idx >= nums.size())
            return;
        for(int i = idx; i < nums.size(); ++i)
        {
            tmp.push_back(nums[i]);
            ret.push_back(tmp);
            dfs(ret, tmp, nums, i+1);
            tmp.pop_back();
        }
    }
};


Conclusion:
middle level algorithm issue, backtracking, time complexity is: O(n*2^n), space complexity is: O(n) (do not consider the call stack memory consuming issue)

Time Complexity Caculation Example: input is: [1,2,3]
the result is: [[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]], which is 2^3 = 8
T(n) = T(n-1) + T(n-2) + T(n-3) + ... + T(1) + T(0)
from this, we can know T(n+1) = 2 * T(n) => T(n) = 2^n * T(0), each caculation needs n operations; thus, the totally time complexity is: 
O(n * 2^n)
