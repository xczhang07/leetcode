/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        int carry = 1;
        dfsHelper(head, carry);
        if(carry)
        {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }
        else
            return head;
    }
    
    void dfsHelper(ListNode*& head, int& carry)
    {
        if(!head)
            return;
        dfsHelper(head->next, carry);
        int sum = head->val + carry;
        head->val = sum%10;
        carry = sum/10;
    }
};


/*
Conclusion:
an middle level algorithm issue, using dfs to reach the bottom of the linked list, then caculate its value from bottom to up.
Time Complexity is: O(n)
Space Complexity isL O(n) recursive.

*/
