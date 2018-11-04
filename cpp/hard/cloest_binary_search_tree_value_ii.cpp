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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ret;
        if(!root)
            return ret;
        dfs_inorder(root, ret, target, k);
        return ret;
    }
    
    void dfs_inorder(TreeNode* root, vector<int>& ret, double& target, int& k)
    {
        if(!root)
            return;
        dfs_inorder(root->left, ret, target, k);
        if(ret.size() < k)
            ret.push_back(root->val);
        else if(abs(root->val-target) < abs(ret[0]-target))
        {
            ret.erase(ret.begin());
            ret.push_back(root->val);
        }
        else
            return;
        dfs_inorder(root->right, ret, target, k);
        return;
    }
};
