Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        Time Complexity is: O(n*2^n)
        Space Complexity is: O(n)
        */
        vector<vector<int>> ret;
        ret.push_back(vector<int>());
        if(nums.size() == 0)
            return ret;
        vector<int> tmp;
        int idx = 0;
        backTracking(ret, nums, tmp, idx);
        return ret;
    }
    
    void backTracking(vector<vector<int>>& ret, vector<int>& nums, vector<int>& tmp, int idx)
    {
        if(idx == nums.size())
            return;
        for(int i = idx; i < nums.size(); ++i)
        {
            tmp.push_back(nums[i]);
            ret.push_back(tmp);
            backTracking(ret, nums, tmp, i+1);
            tmp.pop_back();
        }
        return;
    }
};
