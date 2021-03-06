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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* new_list = new ListNode(0);
        ListNode* new_head = new_list;
        int counter = 0;
        while(t1 != NULL && t2 != NULL)
        {
            int sum = t1->val + t2->val + counter;
            new_head->val = sum % 10;
            counter = sum / 10;
            t1 = t1->next;
            t2 = t2->next;
            if(t1 != NULL && t2 != NULL)
            {
                ListNode* new_node = new ListNode(0);
                new_head->next = new_node;
                new_head = new_head->next;
            }
        }
        while(t1 != NULL)
        {
            int sum = t1->val + counter;
            ListNode* new_node = new ListNode(sum%10);
            counter = sum / 10;
            new_head->next = new_node;
            new_head = new_head->next;
            t1 = t1->next;
        }
        while(t2 != NULL)
        {
            int sum = t2->val + counter;
            ListNode* new_node = new ListNode(sum%10);
            counter = sum / 10;
            new_head->next = new_node;
            new_head = new_head->next;
            t2 = t2->next;
        }
        if(counter == 1)
        {
            ListNode* new_node = new ListNode(counter);
            new_head->next = new_node;
        }
        return new_list;
    }
};

Conclusion:

easy issue, straight forward, time complexity is: O(m+n)
    
    
version 2:

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        int carry = 0, sum = 0;
        ListNode* newList = new ListNode(0);
        ListNode* t = newList;
        while(l1 || l2 || carry)
        {
            sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            t->next = node;
            t = t->next;
            l1 = l1 ? l1->next:l1;
            l2 = l2 ? l2->next:l2;
        }
        return newList->next;
    }
    
    
};
