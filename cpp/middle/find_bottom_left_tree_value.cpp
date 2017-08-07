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
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL)
            return -1;
        int level = 1;
        int max_level = 1;
        int most_left_val = root->val;
        dfs_helper(root, level, max_level, most_left_val);
        return most_left_val;
    }
    
    void dfs_helper(TreeNode* root, int depth, int& max_depth, int& most_left_val)
    {
        if(!root)
            return;
        if(depth > max_depth)
        {
            most_left_val = root->val;
            max_depth = depth;
        }
        dfs_helper(root->left, depth+1, max_depth, most_left_val);
        dfs_helper(root->right, depth+1, max_depth, most_left_val);
    }
};

Conclusion:
an middle level algorithm issue; however, I think this one should be the easy level issue, dfs preorder is pretty good enough to solve this
algorithm issue, each time, we compare the max level has been reached with current level, if current level is larger than the max level has
been reached, then update the most_left_val, and each time we visit the left side first of all; thus, we will always get the most left value
in this algorithm.

Time Complexity: O(n)
Space Complexity: O(1)
