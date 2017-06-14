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
