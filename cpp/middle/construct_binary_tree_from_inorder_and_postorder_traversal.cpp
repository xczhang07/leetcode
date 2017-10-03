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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())
            return NULL;
        else if(inorder.size() == 0)
            return NULL;
        return constructBinaryTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode* constructBinaryTree(vector<int>& inorder, int i_st, int i_end, vector<int>& postorder, int p_st, int p_end)
    {
        if(i_st > i_end || p_st > p_end)
            return NULL;
        TreeNode* root = new TreeNode(postorder[p_end]);
        int root_pos = findRootPosition(inorder, postorder[p_end]);
        int left_size = root_pos - i_st;
        TreeNode* left_tree = constructBinaryTree(inorder, i_st, i_st+left_size-1, postorder, p_st, p_st+left_size-1);
        TreeNode* right_tree = constructBinaryTree(inorder, i_st+left_size+1, i_end, postorder, p_st+left_size, p_end-1);
        root->left = left_tree;
        root->right = right_tree;
        return root;
    }
    
    int findRootPosition(vector<int>& inorder, int val)
    {
        for(int i = 0; i < inorder.size(); ++i)
        {
            if(inorder[i] == val)
                return i;
        }
        return -1;
    }
    
};



Conclustion:

Time Complexity: O(n)
Space Complexity: O(n)
