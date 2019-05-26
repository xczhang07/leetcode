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
    
    int robHelper(TreeNode* root, int& left, int& right)
    {
        if(!root)
            return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        left = robHelper(root->left, ll, lr);
        right = robHelper(root->right, rl, rr);
        return max(root->val+ll+lr+rl+rr, left+right);
    }
    
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        int left = 0, right = 0;
        return robHelper(root, left, right);
    }
};
