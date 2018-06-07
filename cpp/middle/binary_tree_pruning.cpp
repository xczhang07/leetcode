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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return root;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->val == 0 && root->left == NULL && root->right == NULL)
            root = NULL;
        return root;
    }
};


Conclusion:
an middle level algorithm issue; however, IMO, it does not account to a middle difficult level issue, it is easy.
we can use postorder to travel this tree.

Time Complexity: O(n)
Space Complexity: O(1), if it does not contain the call stack of the recurisive.
