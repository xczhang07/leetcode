/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void dfs(TreeNode* node, TreeNode*& parent, int& val, int& height, int h) {
        if(node == NULL) {
            return;
        }
        if(node->left) {
            if(node->left->val == val) {
                parent = node;
                height = h+1;
                return;
            }
        } 
        if(node->right) {
            if(node->right->val == val) {
                parent = node;
                height = h+1;
                return;
            }
        }
        dfs(node->left, parent, val, height, h+1);
        dfs(node->right, parent, val, height, h+1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int x_height = 0, y_height = 0, h = 0;
        TreeNode* x_parent = NULL;
        TreeNode* y_parent = NULL;
        dfs(root, x_parent, x, x_height, h);
        dfs(root, y_parent, y, y_height, h);
        if(x_height == y_height && x_parent != y_parent) {
            return true;
        }
        return false;
    }
};
