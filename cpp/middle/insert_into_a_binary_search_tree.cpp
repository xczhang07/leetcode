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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        TreeNode* node = new TreeNode(val);
        return insert(root, node);
    }
    
    TreeNode* insert(TreeNode* root, TreeNode* node)
    {
        if(!root)
            return node;
        if(root->val < node->val)
            root->right = insert(root->right, node);
        else
            root->left = insert(root->left, node);
        return root;
    }
    
   
};

/*
Conclusion: a middle level algorithm issue, we can use the personality of BST(travel the BST and find the correct position
to insert)
Time Complexity is: O(logN) N is the node number
Space Complexity is: O(h) h is the height of the tree, recursive stack.
*/
