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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        TreeNode* curr = root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode* tmp = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                TreeNode* t = curr;
                while(t->right)
                    t = t->right;
                t->right = tmp;
            }
            curr = curr->right;
        }
    }
};


Time Complexity is: O(n^2)
Space Complexity is: O(1)
