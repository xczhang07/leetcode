写一棵树的镜像树。

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->right = left;
        root->left = right;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
