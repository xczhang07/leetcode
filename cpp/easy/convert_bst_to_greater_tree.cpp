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
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)
            return root;
        int sum = 0;
        dfs_inorder(root, sum);
        return root;
    }
    
    void dfs_inorder(TreeNode* root, int& sum)
    {
        if(root == NULL)
            return;
        dfs_inorder(root->right, sum);
        sum += root->val;
        root->val = sum;
        dfs_inorder(root->left, sum);
        return;
    }
};


Conclusion:

change a little bit on the inorder dfs travel.
Time complexity is: O(n)



