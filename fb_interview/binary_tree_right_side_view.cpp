Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
  
  
Solution#1: BFS
Time Complexity is: O(n)
Space Complexity is: O(n)

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int level = q.size();
            for(int i = 0; i < level; ++i)
            {
                TreeNode* t = q.front();
                q.pop();
                if(i == 0)
                    ret.push_back(t->val);
                if(t->right)
                    q.push(t->right);
                if(t->left)
                    q.push(t->left);
            }
        }
        return ret;
    }
};
