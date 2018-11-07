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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        ret.push_back(root->val);
        getLeftBoundaries(root->left, ret);
        getLeaves(root->left, ret);
        getLeaves(root->right, ret);
        getRightBoundaries(root->right, ret);
        return ret;
    }
    
    void getLeaves(TreeNode* root, vector<int>& ret)
    {
        /* get the leaves of the binary tree from left to right order */
        if(!root)
            return;
        /* if both the left and a right of a node are NULL, we can say that node is leaf node */
        if(root->left == NULL && root->right == NULL)
        {
            ret.push_back(root->val);
            return;
        }
        getLeaves(root->left, ret);
        getLeaves(root->right, ret);
        return;
    }
    
    void getLeftBoundaries(TreeNode* root, vector<int>& ret)
    {
        /* get left boundary from top-down order */
        if(!root)
            return;
        if(root->left)
        {
            ret.push_back(root->val);
            getLeftBoundaries(root->left, ret);
        }
        else if(root->right)
        {
            ret.push_back(root->val);
            getLeftBoundaries(root->right, ret);
        }
    }
    
    void getRightBoundaries(TreeNode* root, vector<int>& ret)
    {
        /* get right boundary from bottom-up order */
        if(!root)
            return;
        if(root->right)
        {
            getRightBoundaries(root->right, ret);
            ret.push_back(root->val);
        }
        else if(root->left)
        {
            getRightBoundaries(root->left, ret);
            ret.push_back(root->val);
        }
    }
    
};

/*
Time Complexity is: O(n)
Space Complexity is: O(n) recursive stack
*/
