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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        if(root->left == NULL)
            return minDepth(root->right) + 1;
        else if(root->right == NULL)
            return minDepth(root->left) + 1;
        else
            return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    
   
};

Conclusion: an easy algorithm issue, which is different with get the max height of binary tree (that one is bottom up, this one is top down)

Time Complexity: O(n)
Space Complexity: O(1)


