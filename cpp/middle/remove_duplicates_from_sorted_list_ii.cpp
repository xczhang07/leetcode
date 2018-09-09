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
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* prev = newHead;
        ListNode* curr = head;
        int prev_val = head->val;
        int appear_nums = 1;
        while(curr && curr->next)
        {
            ListNode* post = curr->next;
            if(post->val == prev_val)
            {
                ++appear_nums;
                curr = curr->next;
            }
            else
            {
                if(appear_nums > 1)
                {
                    prev->next = post;
                    appear_nums = 1;
                    prev_val = post->val;
                    curr = post;
                }
                else
                {
                    prev = prev->next;
                    curr = curr->next;
                    prev_val = curr->val;
                }
            }
        }
	/* corner case, if something like: 1->2->3->4->4, we need ops to process the list*/
        if(appear_nums > 1) prev->next = NULL;
        return newHead->next;
    }
};

/*
Conclusion:
a middle level leetcode algorithm issue, time complexity is: O(n), space complexity is: O(1)
*/
