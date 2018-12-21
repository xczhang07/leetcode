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
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int long_path  = 0;
        dfs(root, root, long_path);
        return long_path;
    }
    
    pair<int,int> dfs(TreeNode* node, TreeNode* parent, int& long_path)
    {
        if(!node)
            return {0,0};
        pair<int,int> left = dfs(node->left, node, long_path);
        pair<int,int> right = dfs(node->right, node, long_path);
        long_path = max(long_path, left.first + right.second+1);
        long_path = max(long_path, left.second + right.first+1);
        int inc = 0, dec = 0;
        if(node->val == parent->val + 1)
            inc = max(left.first, right.first)+1;
        else if(node->val == parent->val - 1)
            dec = max(left.second, right.second)+1;
        return {inc, dec};
    }
};

/*
for me this is not an easy algorithm issue
*/
