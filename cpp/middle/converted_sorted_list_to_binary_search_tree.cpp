/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        return dfs(head, NULL);
    }
    
    TreeNode* dfs(ListNode* head, ListNode* tail)
    {
        if(head == tail)
            return NULL;
        if(head->next == tail)
        {
            TreeNode* newNode = new TreeNode(head->val);
            return newNode;
        }
        ListNode* mid = head;
        ListNode* travel = head;
        while(travel != tail && travel->next != tail)
        {
            mid = mid->next;
            travel = travel->next->next;
        }
        TreeNode* root = new TreeNode(mid->val);
        root->left = dfs(head, mid);
        root->right = dfs(mid->next, tail);
        return root;
    }
    
   
};


/*
Conclusion: an middle level algorithm issue, not too difficult, convert sorted linked list to binary search tree.
Time Complexity: O(n)
Space Complexity: O(1)


*/
