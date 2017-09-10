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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)
            return NULL;
        if(root->val < L)
            return trimBST(root->right, L, R);
        else if(root->val > R)
            return trimBST(root->left, L, R);
        else
        {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
    }
};


Conclusion:
这道题要求写一个算法，根据要求，对二叉树进行剪枝操作。对于给定的一颗二叉树，给出上限和下限，把二叉树中节点值不在这个区间的所有其他节点都除去。
很简单得题，preorder dfs就可以解决这个问题。

Time Complexity: O(n)
Space Complexity: O(1) (不包含recursive stack的空间)
