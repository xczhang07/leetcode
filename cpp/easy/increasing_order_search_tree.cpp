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
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)
            return root;
        TreeNode* tmpNode = new TreeNode(-1);
        TreeNode* travel = tmpNode;
        inorder(root, travel);
        root = tmpNode->right;
        delete tmpNode;
        return root;
    }
    
    void inorder(TreeNode* root, TreeNode*& travel)
    {
        if(!root) 
            return;
        inorder(root->left, travel);
        travel->right = root;
        root->left = NULL;
        travel = travel->right;
        inorder(root->right, travel);
        return;
    }
};


/*
Time Complexity is: O(V)
Space Complexity is: O(V) recursive stack usage
*/
