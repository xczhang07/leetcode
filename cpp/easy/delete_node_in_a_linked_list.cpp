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
    void deleteNode(ListNode* node) {
        if(!node)
            return;
        if(node->next == NULL)
        {
            node = NULL;
            return;
        }
        else
        {
            node->val = node->next->val;
            ListNode* tmp = node->next->next;
            node->next = tmp;
            return;
        }
    }
};


Conclusion:
very easy algorithm issue, copy the node's value which is the next node of the deleted node, 
then deleted node points to the next one.

Time Complexity: O(1)
Space Complexity: O(1)
