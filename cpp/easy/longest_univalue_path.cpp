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
    int longestUnivaluePath(TreeNode* root) {
        if(!root)
            return 0;
        int lup = 0;
        getLUP(root, lup);
        return lup;
    }
    
    int getLUP(TreeNode* node, int& lup)
    {
        if(!node)
            return 0;
        int l_len = 0;
        int r_len = 0;
        int llar = 0 ; /* left sub tree length plus node */
        int rlar = 0; /* right sub tree length plus node*/
        l_len = getLUP(node->left, lup);
        r_len = getLUP(node->right, lup);
        if(node->left && node->val == node->left->val)
            llar = l_len + 1;
        if(node->right && node->val == node->right->val)
            rlar = r_len + 1;
        lup = max(lup, llar + rlar);
        return max(llar, rlar);
    }
};

Conclusion: tag marked as an easy algorithm issue; however, IMO, it looks like not a very easy algorithm issue.
this kind of question is very typical.Caculate the length for corss the node.

Time Complexity: O(N)
Space Complexity: O(H) H is the height of the tree. recursive call stack will be up to the height of the tree.
