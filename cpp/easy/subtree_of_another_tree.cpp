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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL)
            return true;
        else if(s == NULL || t == NULL)
            return false;
        bool cond1 = isSame(s, t);
        bool cond2 = isSubtree(s->left, t);
        bool cond3 = isSubtree(s->right, t);
        return cond1 || cond2 || cond3;
    }
    
    bool isSame(TreeNode* s, TreeNode* t)
    {
        if(!s && !t)
            return true;
        if(!s || !t)
            return false;
        bool l = false;
        bool r = false;
        if(s->val == t->val)
        {
            l = isSame(s->left, t->left);
            r = isSame(s->right, t->right);
            return l&&r;
        }
        else
            return false;
            
    }
};

time complexity:
worst case is: O(mn), assume s has m nodes and t has n nodes, the worst case for each node of s, the instructions of visit t nodes is n times
thus, the totally time complexity is O(mn)
