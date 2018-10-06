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
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        bool valid = true;
        TreeNode* prev = NULL;
        dfs(root, prev, valid);
        return valid;
    }
    
    void dfs(TreeNode* root, TreeNode*& prev, bool& valid)
    {
        if(!root)
            return;
        dfs(root->left, prev, valid);
        if(!prev)
            prev = root;
        else
        {
            if(prev->val >= root->val)
            {
                valid = false;
                return;
            }
            prev = root;
        }
        dfs(root->right, prev, valid);
        return;
    }
};


/*
Conclusion:
dfs inorder travel to binary search tree.
Time Complexity is: O(n)
Space Complexity is:  O(1)
*/
