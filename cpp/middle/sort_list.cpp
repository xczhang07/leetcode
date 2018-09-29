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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
    
    ListNode* mergeSort(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            if(!fast)
                break;
            slow = slow->next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        ListNode* list1 = mergeSort(head); //recursive call
        ListNode* list2 = mergeSort(head2);
        return merge(list1, list2); // merge the two sorted list
    }
    
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        if(!list1)
            return list2;
        else if(!list2)
            return list1;
        ListNode* newList = new ListNode(0);
        ListNode* travel = newList;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                ListNode* newNode = new ListNode(list1->val);
                travel->next = newNode;
                travel = travel->next;
                list1 = list1->next;
            }
            else
            {
                ListNode* newNode = new ListNode(list2->val);
                travel->next = newNode;
                travel = travel->next;
                list2 = list2->next;
            }
        }
        if(list1)
            travel->next = list1;
        if(list2)
            travel->next = list2;
        return newList->next;
    }
    
};

/*
an middle level algorithm issue to sort the linked list, we use merge-sort to resolve this issue.
Time Complexity is: O(nlogn)
Space Complexity is: O(n)
*/
