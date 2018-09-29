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
    int getLen(ListNode* head) {
        if(!head)
            return 0;
        int len = 0;
        while(head) {
            ++len;
            head = head->next;
        }
        return len;
    }
    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = getLen(root);
        int n = len/k;
        int m = len%k;
        int node_num = 0;
        int rest = 0;
        if(n > 0) {
            node_num = n;
            rest = m;
        }
        if(n == 0)  node_num = 1;
        vector<ListNode*> parts(k, NULL);
        ListNode* travel = root;
        int idx = 0;
        while(travel) {
            ListNode* head = travel;
            int step = node_num;
            while(step > 1) {
                travel = travel->next;
                --step;
            }
            if(rest > 0) {
                travel = travel->next;
                --rest;
            }
            ListNode* tmpHead = head;
            head = travel->next;
            travel->next = NULL;
            travel = head;
            parts[idx] = tmpHead;
            ++idx;
        }
        return parts;    
    }
};

/*
Conclusion:
split list into parts, a middle level algorithm issue of leetcode.
Time Complexity: O(n)
Space Complexity: O(1)
*/
