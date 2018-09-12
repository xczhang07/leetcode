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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        int carry = 0;
        int val1 = 0;
        int val2 = 0;
        ListNode* tail = NULL;
        while(l1 != NULL) {
            st1.push(l1);
            l1 = l1->next;
        }
        while(l2 != NULL) {
            st2.push(l2);
            l2 = l2->next;
        }
        while(!st1.empty() || !st2.empty() || carry) {
            int sum = carry;
            if(!st1.empty()) {
                val1 = st1.top()->val;
                sum += val1;
                st1.pop();
            }
            if(!st2.empty()) {
                val2 = st2.top()->val;
                sum += val2;
                st2.pop();
            }
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum%10);
            newNode->next = tail;
            tail = newNode;
        }
        return tail;
    }
    
   
};


/*
Conclusion:
an middle level algorithm issue, not too diffcult, using stack can resolve the issue.
Time Complexity: O(n)
Space Complexity: O(n)
*/
