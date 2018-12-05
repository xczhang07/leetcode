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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || !root->left)
            return root;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        TreeNode* res = upsideDownBinaryTree(l);
        l->left = r;
        l->right = root;
        root->left = NULL;
        root->right = NULL;
        return res;
    }
};

/*
Time Complexity is: O(n)
Space Complexity is: O(1) if we do not count the call stack space.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

Solution 2

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root)
            return root;
        return dfs(root, NULL, NULL);
    }
    
    TreeNode* dfs(TreeNode* node, TreeNode* parent, TreeNode* right)
    {
        if(node->left == NULL)
        {
            node->left = right;
            node->right = parent;
            return node;
        }
        
        TreeNode* newNode = dfs(node->left, node, node->right);
        node->left = right;
        node->right = parent;
        return newNode;
    }
};
