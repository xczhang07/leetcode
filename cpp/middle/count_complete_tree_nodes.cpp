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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh == rh)
            return pow(2, lh)-1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int leftHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1+leftHeight(root->left);
    }
    
    int rightHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1+rightHeight(root->right);
    }
};
