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
    
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        unordered_map<TreeNode*, int> m;
        return rob_helper(root, m);
        
    }
    
    int rob_helper(TreeNode* root, unordered_map<TreeNode*, int>& m)
    {
        if(!root)
            return 0;
        else if(m.find(root) != m.end())
            return m[root];
        int val = 0;
        if(root->left)
            val += rob_helper(root->left->left, m) + rob_helper(root->left->right, m);
        if(root->right)
            val += rob_helper(root->right->left, m) + rob_helper(root->right->right, m);
        val =  max(val + root->val, rob_helper(root->left, m) + rob_helper(root->right, m));
        m[root] = val;
        return val;
    }
    
    
};
