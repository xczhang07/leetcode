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
        if(!root)
            return 0;
        int ret = INT_MIN;
        get_height(root, ret);
        return ret;
    }
    
    int get_height(TreeNode* root, int& ret)
    {
        if(!root)
            return 0;
        int left = get_height(root->left, ret);
        int right = get_height(root->right, ret);
        ret = max(ret, left+right);
        return max(left, right)+1;
    }
};


Conclusion:
caculate the sum of each node's left subtree depth and right subtree depth, get the maxim value.

Time complexity:
O(n) each node will be visit only one time through the function "get_height()"
