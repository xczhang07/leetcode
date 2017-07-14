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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* prev = new_head;
        ListNode* curr = head;
        ListNode* post = head->next;
        while(post != NULL)
        {
            curr->next = post->next;
            post->next = prev->next;
            prev->next = post;
            post = curr->next;
        }
        return new_head->next;
    }
};

Conclusion:
easy algorithm issue, time complexity is: O(n), space complexity is: O(1)
