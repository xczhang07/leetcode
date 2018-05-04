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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        vector<int> tmp;
        dfs(root, sum, ret, tmp);
        return ret;
    }
    
    void dfs(TreeNode* root, int sum, vector<vector<int>>& ret, vector<int> tmp)
    {
        if(!root)
            return;
        sum -= root->val;
        tmp.push_back(root->val);
        if(!sum)
        {
            if(!root->left && !root->right)
            {
                ret.push_back(tmp);
                return;
            }
        }
        dfs(root->left, sum, ret, tmp);
        dfs(root->right, sum, ret, tmp);
        return;
    }
};

Conclusion: easy algorithm issue on leetcode, dfs can resolve the issue, very similar with path sum i

Time Complexity: O(n) visit all the nodes of the tree.
Space Complexity: O(n) 
