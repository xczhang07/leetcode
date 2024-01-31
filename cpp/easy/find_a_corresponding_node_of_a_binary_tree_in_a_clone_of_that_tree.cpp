/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

pre-order traverse.
Time Complexity: O(n)
Time Complexity: O(n) recursive stack.

class Solution {
public:
    void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode*& match) {
        if(original == NULL) {
            return;
        }
        if(original == target) {
            match = cloned;
            return;
        }
        dfs(original->left, cloned->left, target, match);
        dfs(original->right, cloned->right, target, match);
        return;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == NULL || cloned == NULL) {
            return NULL;
        }
        TreeNode* match = NULL;
        dfs(original, cloned, target, match);
        return match;
    }
};
