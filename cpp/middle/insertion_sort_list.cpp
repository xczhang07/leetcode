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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* prev = newHead;
        ListNode* curr = head;
        while(curr->next)
        {
            ListNode* post = curr->next;
            if(post->val < curr->val)
            {
                while(prev->next)
                {
                    if(prev->next->val < post->val)
                        prev = prev->next;
                    else
                        break;
                }
                curr->next = post->next;
                post->next = prev->next;
                prev->next = post;
                prev = newHead;
            }
            else
                curr = curr->next;
        }
        return newHead->next;
    }
};

/*
Conclusion: an middle level algorithm issue, not very diffcult, implement insertion sort should be OK. 
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
