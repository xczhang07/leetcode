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
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        int val = root->val;
        return dfs(root, val);
    }
    
    bool dfs(TreeNode* root, int& val)
    {
        if(!root)
            return true;
        if(root->val == val)
        {
            bool left = dfs(root->left, val);
            bool right = dfs(root->right, val);
            return left && right;
        }
        else
        {
            return false;
        }
    }
};


/*
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
