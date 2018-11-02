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
        TreeLinkNode* curr = root;
        while(curr->left)
        {
            TreeLinkNode* travel = curr;
            while(travel)
            {
                TreeLinkNode* neighbor = travel->next;
                travel->left->next = travel->right;
                if(neighbor)
                {
                    travel->right->next = neighbor->left;   
                }
                travel = travel->next;
            }
            curr = curr->left;
        }
        return;
    }
};

/*
a middle level algorithm issue.
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
