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
    bool isBalanced(TreeNode* root) {
        bool is_balanced = true;
        getHeight(root, is_balanced);
        return is_balanced;
    }
    
    int getHeight(TreeNode* root, bool& is_balanced)
    {
        if(!root)
            return 0;
        int left_height = getHeight(root->left, is_balanced);
        int right_height = getHeight(root->right, is_balanced);
        int height_diff = abs(left_height-right_height);
        if(height_diff > 1)
        {
            is_balanced = false;
            return -1;
        }
        return (left_height > right_height ? left_height : right_height)+1;
    }
};

Conclusion: to check whether or not a binary tree is balanced. 
dfs travel the input tree.

Time Complexity: O(n)
Space Complexity: O(n)
