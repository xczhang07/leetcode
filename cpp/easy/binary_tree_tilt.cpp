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
    int findTilt(TreeNode* root) {
        if(root == NULL)
            return 0;
        int tilt = 0;
        dfs_postorder(root, tilt);
        return tilt;
    }
    
    int dfs_postorder(TreeNode* root, int& tilt)
    {
        if(root == NULL)
            return 0;
        int left_sum = dfs_postorder(root->left, tilt);
        int right_sum = dfs_postorder(root->right, tilt);
        tilt += abs(left_sum-right_sum);
        return left_sum + right_sum + root->val;
    }
};

Conclusion:
easy, dfs, postorder


Another Solution:
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
    int sum = 0;

    void subTreeSum(TreeNode* root, int& sum) {
        if(root == NULL) {
            return;
        }
        sum += root->val;
        subTreeSum(root->left, sum);
        subTreeSum(root->right, sum);
        return;
    }

    int findTilt(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left_sum = 0, right_sum = 0;
        subTreeSum(root->left, left_sum);
        subTreeSum(root->right, right_sum);
        sum += abs(left_sum-right_sum);
        findTilt(root->left);
        findTilt(root->right);
        return sum;
    }
};
