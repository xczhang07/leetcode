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
    pair<TreeNode*, int> lca(TreeNode* node) {
        if(!node) {
            return {NULL, 0};
        }
        auto left = lca(node->left);
        auto right = lca(node->right);
        if(left.first == NULL && right.first == NULL) {
            return {node, 1};
        }
        if(left.second > right.second) {
            return {left.first, left.second+1};
        } else if (left.second < right.second) {
            return {right.first, right.second+1};
        } else {
            return {node, right.second+1};
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto ancestor = lca(root);
        return ancestor.first;
    }
};
