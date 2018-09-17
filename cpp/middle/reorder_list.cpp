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
        if(head == NULL || head->next == NULL)
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
        /* merge the two list */
        ListNode* travel = head;
        while(travel && second)
        {
            ListNode* tmp = second;
            second = second->next;
            tmp->next = travel->next;
            travel->next = tmp;
            if(travel && travel->next)
                travel = travel->next->next;
        }
        return;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        if(!head || !head->next)
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

/*
Conclusion:
an middle level algorithm issue, which is not very diffcult, find the middle node of the linked list, reverse the second part, and merge them.
*/
