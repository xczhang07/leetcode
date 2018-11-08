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
    int countUnivalSubtrees(TreeNode* root) {
        if(!root)
            return 0;
        int counter = 0;
        dfs(root, counter);
        return counter;
    }
    
    bool dfs(TreeNode* root, int& counter)
    {
        /* bottom up solution */
        if(!root)
            return false;
        bool l = true;
        bool r = true;
        if(root->left == NULL && root->right == NULL)
        {
            ++counter;
            return true;
        }
        if(root->left)
            l = dfs(root->left, counter) && root->val == root->left->val;
        if(root->right)
            r = dfs(root->right, counter) && root->val == root->right->val;
        if(l && r)
            ++counter;
        return (l&&r);
    }
};


/*
an middle level algorithm issue. 
Time Complexity is: O(n)
Space Complexity is: O(1)

for this issue, we are using buttom up strategy.
*/
