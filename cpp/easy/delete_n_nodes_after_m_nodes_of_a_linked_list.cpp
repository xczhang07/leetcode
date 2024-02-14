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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        int count = 1;
        ListNode* tmpHead = head;
        ListNode* travel = head;
        while(travel && tmpHead) {
            if(count == m) {
                count = 1;
                int k = 0;
                while(travel != NULL && k < n) {
                    travel = travel->next;
                    ++k;
                }
                if(travel != NULL) {
                    tmpHead->next = travel->next;
                    tmpHead = tmpHead->next;
                    travel = tmpHead;
                } else {
                    tmpHead->next = NULL;
                    break;
                }
            } else {
                tmpHead = tmpHead->next;
                travel = travel->next;
                ++count;
            }
        }
        return head;
    }
};
