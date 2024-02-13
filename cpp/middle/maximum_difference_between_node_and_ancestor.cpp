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
    
    void dfs(TreeNode* node, int maxVal, int minVal, int& maxDiff) {
        if(!node) {
            return;
        }
        maxVal = max(maxVal, node->val);
        minVal = min(minVal, node->val);
        maxDiff = max(maxDiff, maxVal - minVal);
        dfs(node->left, maxVal, minVal, maxDiff);
        dfs(node->right, maxVal, minVal, maxDiff);
        return;
    }

    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = INT_MIN;
        int maxVal = root->val, minVal = root->val;
        dfs(root, maxVal, minVal, maxDiff);
        return maxDiff;
    }
};
