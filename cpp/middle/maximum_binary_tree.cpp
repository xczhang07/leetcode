/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        return dfs_helper(nums, 0, nums.size()-1);
    }
    
    TreeNode* dfs_helper(vector<int>& nums, int start, int end)
    {
        if(start > end || start >= nums.size() || end < 0)
            return NULL;
        int max_idx = start;
        for(int i = start; i <= end; ++i)
        {
            if(nums[i] > nums[max_idx])
                max_idx = i;
        }
        TreeNode* root = new TreeNode(nums[max_idx]);
        root->left = dfs_helper(nums, start, max_idx-1);
        root->right = dfs_helper(nums, max_idx+1, end);
        return root;
    }
};


Conclustion:
a middle level algorithm issue, find the largest value of the input array between start and end, then recursive calling the function to
find the left side and right side maximum value of the subarray.
Time Complexity: O(n)
Space Complexity: O(1)
