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
    
    pair<int, TreeNode*> find(TreeNode* root)
    {
        if(!root)
            return make_pair(0, root);
        auto left = find(root->left);
        auto right = find(root->right);
        if(left.first == right.first)
            return make_pair(left.first+1, root);
        else if(left.first > right.first)
            return make_pair(left.first+1, left.second);
        else
            return make_pair(right.first+1, right.second);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
            return NULL;
        return find(root).second;
    }
    
    
};


Time Complexity is: O(n)
