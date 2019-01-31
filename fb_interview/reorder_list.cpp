Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.


Time Complexity is: O(n)
Space Complexity is: O(1)


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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;
        second = reverseList(second);
        ListNode* travel = head;
        while(travel && second)
        {
            ListNode* tmp = second->next;
            second->next = travel->next;
            travel->next = second;
            travel = travel->next->next;
            second = tmp;
        }
        return;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* curr = head;
        ListNode* prev = newHead;
        while(curr->next)
        {
            ListNode* post = curr->next;
            curr->next = post->next;
            post->next = prev->next;
            prev->next = post;
        }
        return newHead->next;
    }
};
