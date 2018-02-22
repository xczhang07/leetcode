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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        int currLevel = 0;
        dfs(ret, currLevel, root);
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    void dfs(vector<vector<int>>& ret, int currLevel, TreeNode* root)
    {
        if(!root)
            return;
        if(ret.empty() || currLevel > ret.size() - 1)
            ret.push_back(vector<int> ());
        ret[currLevel].push_back(root->val);
        dfs(ret, currLevel+1, root->left);
        dfs(ret, currLevel+1, root->right);
        return;
    }
};


Conclusion: preorder dfs can resolve this issue very easy

Time Complexity: O(n)
Space Complexity: O(n)
