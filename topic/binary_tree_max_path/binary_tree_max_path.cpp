/*
On leetcode, there are several algorithm questions about the topic to calculate the largest path sum(start from and end at any
node). 
The approach for this kind issue is to calculate the left subtree path and righ subtree path of every node, then compare
the largest value with the sum of (left + right + root->val). 

https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
https://leetcode.com/problems/diameter-of-binary-tree/description/
*/

binary tree maximum path sum:
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
       if(!root) return 0;
        int max_path = INT_MIN;
        dfs(root, max_path);
        return max_path;
    }
    
    int dfs(TreeNode* root, int& max_path)
    {
        if(!root) return 0;
        int left = dfs(root->left, max_path);
        int right = dfs(root->right, max_path);
        if(left < 0) left = 0;
        if(right < 0) right = 0;
        max_path = max(max_path, left + right + root->val); /* cross node */
        return max(left, right) + root->val;
    }
    
    
};

diameter of binary tree:
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int max_diameter = INT_MIN;
        getDiameter(root, max_diameter);
        return max_diameter;
    }
    
    int getDiameter(TreeNode* root, int& max_diameter)
    {
        if(!root) return 0;
        int left = getDiameter(root->left, max_diameter);
        int right = getDiameter(root->right, max_diameter);
        max_diameter = max(max_diameter, left+right);
        return max(left, right)+1;
    }
    
    
};
