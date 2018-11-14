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
        if(!p)
            return NULL;
        TreeNode* successor = NULL;
        int visit = 0;
        dfs(root, p, successor, visit);
        return successor;
    }
    
    void dfs(TreeNode* root, TreeNode* p, TreeNode*& successor, int& visit)
    {
        if(!root)
            return;
        dfs(root->left, p, successor, visit);
        if(root->val == p->val)
            visit++;
        else
        {
            if(visit == 1)
            {
                successor = root;
                visit = 2;
            }
        }
        dfs(root->right, p, successor, visit);
        return;
    }
};

/*
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
