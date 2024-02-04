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
    void dfs(TreeNode* node, vector<int> paths, long long& sum) {
        if(node == NULL) {
            return;
        }
        paths.push_back(node->val);
        if(node->left == NULL && node->right == NULL) {
            long long tmp = 0;
            for(int i = paths.size()-1; i >= 0; --i) {
                tmp = tmp + pow(2, paths.size()-1-i) * paths[i];
            }
            sum += tmp;
        }
        dfs(node->left, paths, sum);
        dfs(node->right, paths, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        vector<int> path;
        long long sum = 0;
        dfs(root, path, sum);
        return sum;
    }
};
