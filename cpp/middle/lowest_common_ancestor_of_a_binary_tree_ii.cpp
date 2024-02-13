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

    bool findNode(TreeNode* root, TreeNode* node) {
        if(root == NULL || node == NULL) {
            return false;
        }
        if(root == node) {
            return true;
        }
        return findNode(root->left, node) || findNode(root->right, node);
    }

    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }
        if(root == p || root == q) {
            return root;
        }
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if(left && right) {
            return root;
        }
        return left ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(findNode(root, p) && findNode(root, q)) {
            return lca(root, p, q);
        } else {
            return NULL;
        }
    }
};
