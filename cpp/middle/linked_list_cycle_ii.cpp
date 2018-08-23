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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        while(fastPtr && fastPtr->next)
        {
            fastPtr = fastPtr->next->next;
            if(!fastPtr)
                return NULL;
            slowPtr = slowPtr->next;
            if(fastPtr == slowPtr)
                break;
        }
        if(fastPtr == NULL||fastPtr->next == NULL)
            return NULL;
        slowPtr = head;
        while(slowPtr != fastPtr)
        {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        return fastPtr;
    }
};


/*
Conclusion: an middle level algorithm issue on leetcode. Not diffcult, we can set two pointers, one is slow, each time moving 1 step
another one is fastPtr, each time move 2 steps. we can assume that the distance between head of linked list to the start node of circle is
a, when they meetup together, the distance between the node they meetup and the start node is b
so slowPtr moves distance is: a + b
fastPtr moves distance is: a + b + n*c
because of the speed of fastPtr is 2 times for slowPtr, so the relationship is: 2*(a+b) = a + b + n*c => a + b = c
thus, we can move one to the beginning of the list, once they move a, another one is also reached at the entry node of circle

Time Complexity: O(n)
Space Complexity: O(1)

*/
