Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

Example 1:

Input:

   1
    \
     3
    / \
   2   4
        \
         5

Output: 3

Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
Example 2:

Input:

   2
    \
     3
    / 
   2    
  / 
 1

Output: 2 

Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.


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
    void caculate(TreeNode* root, int& ret, int path)
    {
        if(!root)
            return;
        if(root->left)
        {
            if(root->left->val == root->val+1)
            {
                ret = max(ret, path+1);
                caculate(root->left, ret, path+1);
            }
            else
            {
                caculate(root->left, ret, 1);
            }
        }
        if(root->right)
        {
            if(root->right->val == root->val+1)
            {
                ret = max(ret, path+1);
                caculate(root->right, ret, path+1);
            }
            else
                caculate(root->right, ret, 1);
        }
        return;
    }
    
    int longestConsecutive(TreeNode* root) {
        if(!root)
            return 0;
        int longestPath = 1;
        int path = 1;
        caculate(root, longestPath, path);
        return longestPath;
    }
};
