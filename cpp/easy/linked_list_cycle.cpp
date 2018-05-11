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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow)
        {
            slow = slow->next;
            if(fast->next && fast->next->next)
                fast = fast->next->next;
            else
                return false;
            if(slow == fast)
                return true;
        }
        return false;
    }
};

Conclusion: an easy level algorithm issue on leetcode, no comments.
Time Complexity: O(n)
Space Complexity: O(1)
