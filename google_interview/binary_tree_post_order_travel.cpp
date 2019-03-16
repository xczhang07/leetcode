travel binary tree with post-order

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        stack<TreeNode*> in, out;
        in.push(root);
        while(!in.empty())
        {
            TreeNode* t = in.top();
            in.pop();
            out.push(t);
            if(t->left)
                in.push(t->left);
            if(t->right)
                in.push(t->right);
        }
        
        while(!out.empty())
        {
            ret.push_back(out.top()->val);
            out.pop();
        }
        return ret;
            
    }
};
