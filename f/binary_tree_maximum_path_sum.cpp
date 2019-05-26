Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.


Time Complexity is: O(n)
Space Complexity is: O(n) <== count the recursive call stack.

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
    int maxPathSum(TreeNode* root) {
        /* time complexity is O(n), we use postorder to travel the tree */
        if(!root)
            return 0;
        int max_path = INT_MIN;
        dfs(root, max_path);
        return max_path;
    }
    
    int dfs(TreeNode* root, int& max_path)
    {
        if(!root)
            return 0;
        int left = max(0 , dfs(root->left, max_path));
        int right = max(0, dfs(root->right, max_path));
        max_path = max(max_path, left + right + root->val);
        return max(left, right) + root->val;
    }
};
