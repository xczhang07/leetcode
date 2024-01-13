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


# Do it in one pass.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) {
            return head;
        }
        if(n == 0) {
            return head;
        }
        ListNode* fast = head, *slow = head;
        for(int i = 0; i < n; ++i) {
            fast = fast -> next;
        }
        if(!fast) {
            return head->next;
        }
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
