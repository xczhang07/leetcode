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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size())
            return NULL;
        else if(inorder.size() == 0)
            return NULL;
        return constructBinaryTree(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1);
    }
    
    TreeNode* constructBinaryTree(vector<int>& inorder, int i_st, int i_end, vector<int>& preorder, int p_st, int p_end)
    {
        if(i_st > i_end || p_st > p_end)
            return NULL;
        TreeNode* root = new TreeNode(preorder[p_st]);
        int root_idx = getRootIndex(inorder, preorder[p_st]);
        int left_size = root_idx - i_st;
        TreeNode* left_tree = constructBinaryTree(inorder, i_st, i_st+left_size-1, preorder, p_st+1, p_st+left_size);
        TreeNode* right_tree = constructBinaryTree(inorder, i_st+left_size+1, i_end, preorder, p_st+left_size+1, p_end);
        root->left = left_tree;
        root->right = right_tree;
        return root;
    }
    
    int getRootIndex(vector<int>& inorder, int val)
    {
        for(int i = 0; i < inorder.size(); ++i)
        {
            if(inorder[i] == val)
                return i;
        }
        return -1;
    }
};


Conclusion:
a medium level algorithm issue, given the inorder traversal and preorder traversal of a tree, required to reconstruct this tree according to
those two orders.
As common sense, we know that, the first element of the preorder is the tree's root node, according to this value, we can find the position
of this value in the inorder travesal array, then the left part of this element is the left subtree, and the right part of this element is the
right sub tree. Then we do it recursively, and we will get this tree finally.
Time Complexity: O(n)
Space Complexity: O(1)
    
    
Solution 2: easy to understand 
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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
       int root = 0;
        return helper(pre, root, in, 0, in.size()-1);
    }
    
    TreeNode* helper(vector<int>& pre, int& rt, vector<int>& in, int in_st, int in_end)
    {
        if(rt == pre.size() || in_st > in_end)
            return NULL;
        
        TreeNode* root = new TreeNode(pre[rt]);
        int idx = getIndex(in, pre[rt]); /* get the root index in inorder */
        rt++;
        root->left = helper(pre, rt, in, in_st, idx-1);
        root->right = helper(pre, rt, in, idx+1, in_end);
        return root;
    }
   
    
    int getIndex(vector<int>& inorder, int val)
    {
        for(int i = 0; i < inorder.size(); ++i)
        {
            if(inorder[i] == val)
                return i;
        }
        return -1;
    }
};
