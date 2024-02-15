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
    ListNode* mergeNodes(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* tmpHead = new ListNode(-1);
        tmpHead->next = head;
        ListNode* prev = tmpHead;
        ListNode* travel = head;
        while(travel) {
            if(travel->val == 0) {
                ListNode* tmp = travel->next;
                int sum = 0;
                while(tmp->val != 0) {
                    sum += tmp->val;
                    tmp = tmp->next;
                }
                ListNode* newNode = new ListNode(sum);
                prev->next = newNode;
                newNode->next = tmp;
                travel = tmp;
                prev = newNode;
                if(tmp->next == NULL) {
                   prev->next = NULL;
                   break;
                }
            }
        }
        return tmpHead->next;
    }
};
