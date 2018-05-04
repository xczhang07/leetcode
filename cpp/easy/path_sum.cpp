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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        return dfs(root, sum);
    }
    
    bool dfs(TreeNode* root, int sum)
    {
        if(!root)
            return false;
        sum = sum - root->val;
        if(sum == 0)
        {
            if(root->left == NULL && root->right == NULL)
                return true;
        }
        return dfs(root->left, sum) || dfs(root->right, sum);
    }
};

Conclusion: an easy algorithm issue of leetcode, dfs travelsal of binary tree.

Time Complexity: O(n)
Space Complexity: O(n) recursive call stack space consuming
