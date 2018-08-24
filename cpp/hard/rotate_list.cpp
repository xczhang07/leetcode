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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int len = getLen(head); /* get the length of the linkedin list */
        k = k % len; /* caculate the result to see how many steps need to rotate */
        if(k == 0)
            return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        int rest_len = len - k;
        ListNode* travel = newHead;
        while(rest_len > 0)
        {
            travel = travel->next;
            --rest_len;
        }
        ListNode* rotate_head = travel->next;
        travel->next = NULL;
        travel = rotate_head;
        while(travel->next)
            travel = travel->next;
        travel->next = newHead->next;
        return rotate_head;
    }
    
    int getLen(ListNode* head)
    {
        if(!head)
            return 0;
        int len = 0;
        while(head)
        {
            ++len;
            head = head->next;
        }
        return len;
    }
};

Conclustion:
a middle level issue on leetcode, very easy, no comments.
Time Complexity: O(N)
Space Complexity: O(1)
