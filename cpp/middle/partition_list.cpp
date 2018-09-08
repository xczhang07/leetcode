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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* prev = newHead;
        ListNode* travel = head;
        while(travel && travel->val < x)
        {
            travel = travel->next;
            prev = prev->next;
        }
        ListNode* tmp = prev;
        while(travel)
        {
            if(travel->val >= x)
            {
                travel = travel->next;
                tmp = tmp->next;
            }
            else
            {
                tmp->next = travel->next;
                travel->next = prev->next;
                prev->next = travel;
                prev = prev->next;
                travel = tmp->next;
            }
        }
        return newHead->next;
    }
};


/*
Conclusion: a linked list issue on leetcode, middle level algorithm issue.
Time Complexity: O(n)
Space Complexity: O(1)
*/
