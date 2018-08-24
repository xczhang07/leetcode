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
    ListNode* middleNode(ListNode* head) {
        int len = getLen(head);
        int n = len/2 + 1;
        ListNode* travel = head;
        while(n > 1)
        {
            travel = travel->next;
            --n;
        }
        return travel;
    }
    
    int getLen(ListNode* head)
    {
        if(!head)
            return 0;
        int len = 0;
        ListNode* travel = head;
        while(travel)
        {
            travel = travel->next;
            ++len;
        }
        return len;
    }
};


/*
Conclusion:
an easy level leetcode algorithm issue, not too much comments.

Time Complexity: O(n)
Space Complexity: O(1)
*/
