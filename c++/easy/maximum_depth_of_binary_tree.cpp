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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        return max(left_height, right_height)+1;
    }
};

Conclustion:
easy DFS, no any other comments
time complexity: O(n), n is the total node number
space complexity: O(1)
