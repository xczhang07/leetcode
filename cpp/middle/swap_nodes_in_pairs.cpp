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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* prev = newHead;
        ListNode* curr = head;
        ListNode* post = head->next;
        while(curr)
        {
            post = curr->next;
            if(post == NULL)
                break;
            prev->next = post;
            curr->next = post->next;
            post->next = curr;
            prev = curr;
            curr = prev->next;
        }
        return newHead->next;
        
    }
};

/*
Conclusion:
a middle level algorithm issue, not diffcult, easy to resolve
pointer manipulation!
Time Complexity: O(N)
Space Complexity: O(1)
*/
