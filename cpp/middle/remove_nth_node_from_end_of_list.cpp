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
    /* straight forward solution */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        int len = getLen(head);
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* travel = newHead;
        int m = 0;
        while(m != len-n)
        {
            travel = travel->next;
            ++m;
        }
        ListNode* post = travel->next;
        travel->next = post->next;
        return newHead->next;
    }
    
    int getLen(ListNode* head)
    {
        if(!head)
            return 0;
        ListNode* tmp = head;
        int len = 1;
        while(tmp->next)
        {
            tmp = tmp->next;
            len++;
        }
        return len;
    }
};


/*
Conclusion:
a middle level issue of leetcode, this solution is pretty much straight forward, no any other comments on it.
Time Complexity: O(n)
Space Complexity: O1)
*/
