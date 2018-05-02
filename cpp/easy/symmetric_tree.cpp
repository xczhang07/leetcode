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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
            return true;
        else if(left == NULL || right == NULL)
            return false;
        else if(left->val == right->val)
            return isMirror(left->right, right->left) && isMirror(left->left, right->right);
        return false;
    }
};


Conclusion:
An easy algorithm issue on leetcode, check a tree whether or not is a symmetric tree.
we can use recursive to travel the entire tree, then we can get the result.

Time Complexity: according to travel the entire tree, the time complexity is: O(n)
Space Complexity: according to the recursive call, the worst case is the call stack is: O(n)
