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
        if(!root) return;
        TreeLinkNode* dummy = new TreeLinkNode(0);
        while(root)
        {
            TreeLinkNode* travel = dummy;
            dummy->next = NULL;
            while(root)
            {
                if(root->left)
                {
                    travel->next = root->left;
                    travel = travel->next;
                }
                if(root->right)
                {
                    travel->next = root->right;
                    travel = travel->next;
                }
                root = root->next;
            }
            root = dummy->next;
        }
        delete dummy;
        return;
    }
};


/*
a middle level algorithm issue, we can use bfs to travel the input binary tree, this tree is not balanced tree.
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
