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
        if(!root)
            return 0;
        int max_value = INT_MIN;
        dfs(root, max_value);
        return max_value;
    }
    
    int dfs(TreeNode* root, int& res)
    {
        if(!root)
            return 0;
        int left_sum = max(dfs(root->left, res), 0);
        int right_sum = max(dfs(root->right, res), 0);
        res = max(res, left_sum + right_sum + root->val);
        return max(left_sum, right_sum) + root->val;
    }
};

/*
a diffcult issue on leetcode, please refer the following the link:
http://www.cnblogs.com/grandyang/p/4280120.html
Time Complexity: O(n) n is the node number.
Space Complexity: O(n) recursive stack
*/
