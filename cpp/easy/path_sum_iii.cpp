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
    
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        int ret = 0;
        dfs(root, ret, sum);
        return ret+pathSum(root->left, sum)+pathSum(root->right, sum);
    }
    
    void dfs(TreeNode* root, int& ret, int& sum)
    {
        if(!root)
            return;
        sum = sum - root->val;
        if(sum == 0)
            ++ret;
        dfs(root->left, ret, sum);
        dfs(root->right, ret, sum);
        sum += root->val;
    }
};


Conclusion: an easy algorithm issue of leetcode, path sum, dfs tree traverse. very standard typical issue.
