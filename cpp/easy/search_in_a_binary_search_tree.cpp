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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        TreeNode* target = NULL;
        dfs(root, target, val);
        return target;
    }
    
    void dfs(TreeNode* root, TreeNode*& target, int& val)
    {
        if(!root) return;
        if(root->val == val)
        {
            target = root;
            return;
        }
        else if(root->val < val)
            dfs(root->right, target, val);
        else
            dfs(root->left, target, val);
        return;
    }
};

/*
Conclusion: an easy level algorithm issue, binary search concept used.

*/
