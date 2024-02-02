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
    void dfs(TreeNode* node, int& sum) {
        if(node == NULL) {
            return;
        }
        dfs(node->right, sum);
        if(sum == 0) {
            sum = node->val;
        } else {
            int tmp_node_val = node->val;
            node->val += sum;
            sum += tmp_node_val;
        }
        dfs(node->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        int sum = 0;
        dfs(root, sum);
        return root;
    }
};
