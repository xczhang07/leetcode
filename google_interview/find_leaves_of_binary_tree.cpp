Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

 

Example:

Input: [1,2,3,4,5]
  
          1
         / \
        2   3
       / \     
      4   5    

Output: [[4,5,3],[2],[1]]
 

Explanation:

1. Removing the leaves [4,5,3] would result in this tree:

          1
         / 
        2          
 

2. Now removing the leaf [2] would result in this tree:

          1          
 

3. Now removing the leaf [1] would result in the empty tree:

          []         

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> leaves;
        if(!root)
            return leaves;
        getLeaves(root, leaves);
        return leaves;
    }
    
    int getLeaves(TreeNode* root, vector<vector<int>>& leaves)
    {
        if(!root)
            return 0;
        int l = getLeaves(root->left, leaves);
        int r = getLeaves(root->right, leaves);
        int level = max(l, r)+1;
        if(level > leaves.size())
            leaves.push_back(vector<int>());
        leaves[level-1].push_back(root->val);
        return level;
    }
    
   
   
};
