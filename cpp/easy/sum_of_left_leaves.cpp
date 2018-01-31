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
    int sumOfLeftLeaves(TreeNode* root) {
        int ret = 0;
        if(!root)
            return ret;
        if(root->left == NULL && root->right == NULL)
            return ret;
        bool is_left = false;
        dfs(root, is_left, ret);
        return ret;
    }
    
    void dfs(TreeNode* root, bool is_left, int& ret)
    {
        if(!root)
            return;
        if(is_left)
        {
            if(root->left == NULL && root->right == NULL)
                ret += root->val;
        }
        if(root->left)
        {
            is_left = true;
            dfs(root->left, is_left, ret);
        }
        if(root->right)
        {
            is_left = false;
            dfs(root->right, is_left, ret);
        }
        return;
    }
};

Conclusion:
an easy algorithm issue, using dfs preorder can resolve this issue.

Time Complexity is: O(n) n is the node number
Space Complexity is: O(1), which does not include the recursive stack
