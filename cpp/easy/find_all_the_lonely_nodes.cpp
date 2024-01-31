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
    void dfs(TreeNode* root, vector<int>& ret) {
        if(!root) {
            return;
        }
        if(root->left == NULL && root->right != NULL) {
            ret.push_back(root->right->val);
            return dfs(root->right, ret);
        } else if(root->left != NULL && root->right == NULL) {
            ret.push_back(root->left->val);
            return dfs(root->left, ret);
        } else {
            dfs(root->left, ret);
            dfs(root->right, ret);
            return;
        }
    }

    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ret;
        if(root == NULL) {
            return ret;
        }
        dfs(root, ret);
        return ret;
    }
};
