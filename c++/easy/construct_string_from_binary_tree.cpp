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
    string tree2str(TreeNode* t) {
        string ret = "";
        if(t == NULL)
            return ret;
        ret += to_string(t->val);
        preorder_travel(t, ret);
        return ret;
    }
    
    void preorder_travel(TreeNode* t, string& ret)
    {
        if(t->left == NULL && t->right == NULL)
            return;
        if(t->left == NULL)
            ret += "()";
        if(t->left != NULL)
        {
            ret = ret + "(" + to_string(t->left->val);
            preorder_travel(t->left, ret);
            ret += ")";
        }
        if(t->right == NULL)
            return;
        if(t->right != NULL)
        {
            ret = ret + "(" + to_string(t->right->val);
            preorder_travel(t->right, ret);
            ret += ")";
        }
        return;
    }
};
