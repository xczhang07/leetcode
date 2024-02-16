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
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        stack<ListNode*> st;
        st.push(head);
        stack<ListNode*> tmpSt;
        int min_val = head->val;
        ListNode* travel = head->next;
        while(travel) {
            if(travel->val > min_val) {
                while(!st.empty()) {
                    ListNode* node = st.top();
                    st.pop();
                    if(node->val >= travel->val) {
                        tmpSt.push(node);
                    }
                }
                while(!tmpSt.empty()) {
                    st.push(tmpSt.top());
                    tmpSt.pop();
                }
                st.push(travel);
                min_val = travel->val;
            } else {
                min_val = travel->val;
                st.push(travel);
            }
            travel = travel->next;
        }
        while(!st.empty()) {
            tmpSt.push(st.top());
            st.pop();
        }
        ListNode* newList = new ListNode(-1);
        travel = newList;
        while(!tmpSt.empty()) {
            travel->next = tmpSt.top();
            tmpSt.pop();
            travel = travel->next;
        }
        travel->next = NULL;
        return newList->next;
    }
};
