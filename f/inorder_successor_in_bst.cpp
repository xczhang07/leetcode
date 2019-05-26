Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

 

Example 1:


Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
Example 2:


Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
 

Note:

If the given node has no in-order successor in the tree, return null.
It's guaranteed that the values of the tree are unique.


/*
Time Complexity is: O(N)
Space Complexity is: O(N) recursive call
*/

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root)
            return NULL;
        TreeNode* prev = NULL;
        TreeNode* succor = NULL;
        dfs(root, prev, p, succor);
        return succor;
    }
    
    void dfs(TreeNode* root, TreeNode*& prev, TreeNode* p, TreeNode*& succor)
    {
        if(!root)
            return;
        dfs(root->left, prev, p, succor);
        if(prev == p)
            succor = root;
        prev = root;
        dfs(root->right, prev, p, succor);
        return;
    }
};
