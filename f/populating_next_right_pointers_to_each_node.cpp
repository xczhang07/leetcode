Time Complexity is: O(n)
Space Complexity is: O(1)

the input tree is a perfect binary tree

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        TreeLinkNode* curr = root;
        while(curr->left)
        {
            TreeLinkNode* t = curr;
            while(t)
            {
                t->left->next = t->right;
                if(t->next)
                    t->right->next = t->next->left;
                t = t->next;
            }
            curr = curr->left;
        }
    }
};
