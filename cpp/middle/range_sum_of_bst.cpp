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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)
            return 0;
        int sum = 0;
        dfs(root, sum, L, R);
        return sum;
    }
    
    void dfs(TreeNode* root, int& sum, int& L, int& R)
    {
        if(!root)
            return;
        if(root->val >= L && root->val <= R)
        {
            sum += root->val;
            dfs(root->left, sum, L, R);
            dfs(root->right, sum, L, R);
            return;
        }
        else if(root->val < L)
            dfs(root->right, sum, L, R);
        else if(root->val > R)
            dfs(root->left, sum, L, R);
    }
};
