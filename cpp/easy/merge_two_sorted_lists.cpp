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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* newList = NULL;
        if(l1->val <= l2->val)
        {
            newList = l1;
            l1 = l1->next;
        }
        else
        {
            newList = l2;
            l2 = l2->next;
        }
        ListNode* travel = newList;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                travel->next = l1;
                travel = travel->next;
                l1 = l1->next;
            }
            else
            {
                travel->next = l2;
                travel = travel->next;
                l2 = l2->next;
            }
        }
        if(l1)
            travel->next = l1;
        if(l2)
            travel->next = l2;
        return newList;
    }
};

/*
an easy algorithm issue, merge two sorted list.
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
