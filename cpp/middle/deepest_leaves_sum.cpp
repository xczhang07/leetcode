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
    int getHeight(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        return max(left_height, right_height)+1;
    }

    void getDeepestSum(TreeNode* root, int& level, int curr_height, int& sum) {
        if(!root) {
            return;
        }
        if(level == curr_height) {
            sum += root->val;
            return;
        }
        getDeepestSum(root->left, level, curr_height+1, sum);
        getDeepestSum(root->right, level, curr_height+1, sum);
        return;
    }

    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int level = getHeight(root);
        int sum = 0;
        int curr_height = 1;
        getDeepestSum(root, level, curr_height, sum);
        return sum;
    }
};
