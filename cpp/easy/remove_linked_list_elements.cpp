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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* prev = newHead;
        ListNode* curr = head;
        while(curr)
        {
            if(curr->val == val)
            {
                ListNode* post = curr->next;
                prev->next = post;
                curr = post;
            }
            else
            {
                prev = prev->next;
                curr = prev->next;
            }
        }
        return newHead->next;
    }
};

Conclusion: an easy algorithm issue on leetcode, no comments.
Time Complexity: O(n)
Space Complexity: O(1)
