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
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int path = 1;
        int ret = 1;
        dfs(root, ret, path);
        return ret;
    }
    
    void dfs(TreeNode* root, int& ret, int path)
    {
        if(!root)
            return;
        if(root->left)
        {
            if(root->left->val == root->val+1)
            {
                ret = max(ret, path+1);
                dfs(root->left, ret, path+1);
            }
            else
                dfs(root->left, ret, 1);
            
        }
        if(root->right)
        {
            if(root->right->val == root->val+1)
            {
                ret = max(ret, path+1);
                dfs(root->right, ret, path+1);
            }
            else
                dfs(root->right, ret, 1);
            
        }
        return;
    }
};


/*
Time Complexity is: O(n)
Space Complexity is: O(1) not includes the recursive stack.
*/
