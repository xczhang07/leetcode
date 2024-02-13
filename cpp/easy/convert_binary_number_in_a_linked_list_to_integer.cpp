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
    int getDecimalValue(ListNode* head) {
        if(head == NULL) {
            return 0;
        }
        string binary_num;
        int decimal = 0;
        ListNode* travel = head;
        while(travel) {
            binary_num = binary_num + to_string(travel->val);
            travel = travel->next;
        }
        for(int i = binary_num.size()-1; i >= 0; --i) {
            decimal = decimal + (binary_num[i]-'0') * pow(2, binary_num.size()-1-i);
        }
        return decimal;
    }
};
