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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        /* create a temporary head */
        ListNode* temp_head = new ListNode(0);
        temp_head->next = head;
        ListNode* curr = temp_head->next;
        ListNode* post = curr->next;
        while(post)
        {
            if(curr->val == post->val)
            {
                ListNode* node = post->next;
                curr->next = node;
                post = curr->next;
            }
            else
            {
                curr = curr->next;
                post = curr->next;
            }
        }
        return temp_head->next;
    }
};


Conclusion: an easy algorithm issue of leetcode, no more comments, insert a new temp head.
Time Complexity: O(n)
Space Complexity: O(1)

