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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int height = getHeight(root);
        vector<vector<int>> ret(height, vector<int>());
        dfs(ret, root, 0);
        return ret;
    }
    
    void dfs(vector<vector<int>>& ret, TreeNode* root, int idx)
    {
        if(!root)
            return;
        ret[idx].push_back(root->val);
        dfs(ret, root->left, idx+1);
        dfs(ret, root->right, idx+1);
        return;
    }
    
    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return (left > right?left:right)+1;
    }
};


Conclusion: a middle level algorithm issue, first, get the height of the tree, then travel the whole tree from root to leaf,
insert the node into the ret level by level.
Time Complexity: O(n)
Space Complexity: O(n)


