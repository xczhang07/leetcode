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
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL)
            return 0;
        int pre = -1; //because the node value is non-negative
        int ret = INT_MAX;
        dfs_inorder(root, pre, ret);
        return ret;
    }
    
    void dfs_inorder(TreeNode* root, int& pre, int& ret)
    {
        if(root == NULL)
            return;
        dfs_inorder(root->left, pre, ret);
        if(pre != -1)
            ret = min(ret, root->val-pre);
        pre = root->val; //get the pre value before go to the right subtree(the bst is always right side larger than root and                //left side)
        dfs_inorder(root->right, pre, ret);
    }
};


Conclusion:
when we perform inorder travel, we can got a sorted number list; in this case, we just need to perform the inorder travel and use
a variable to store the pre-value of the node, then caculate the min-distance of list.

This methond is a pattern! great algorithm issue
