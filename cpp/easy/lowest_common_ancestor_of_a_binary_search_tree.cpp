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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p ,q);
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};


Conclusion: an easy algorithm issue of leetcode, find the common lowest ancestor of a binary search tree.

The key point is BST. eash to search.


Time Complexity: O(n)
Space Complexity: O(n)
