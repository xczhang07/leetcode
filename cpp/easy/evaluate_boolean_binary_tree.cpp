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
Time Complexity is: O(N)
Space Complexity is: O(N)

class Solution {
public:

    bool dfs(TreeNode* node) {
        if(node == NULL) {
            return true;
        }
        if(node->left == NULL && node->right == NULL) {
            return node->val == 1;
        }
        bool left_logic = dfs(node->left);
        bool right_logic = dfs(node->right);
        if(node->val == 2) {
            return left_logic || right_logic;
        } else {
            return left_logic && right_logic;
        }
    }
    
    bool evaluateTree(TreeNode* root) {
        if(root == NULL) {
            return false;
        }
        if(root->left == NULL && root->right == NULL) {
            return root->val == 1;
        }
        return dfs(root);
    }
};
