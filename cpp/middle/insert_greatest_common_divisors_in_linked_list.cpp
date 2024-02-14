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
    // Caculate the gcd of two numbers.
    int getGcd(int a, int b) {
        if(b == 0) {
            return a;
        }
        return getGcd(b, a%b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* travel = head;
        while(travel && travel->next) {
            int a = travel->val;
            int b = travel->next->val;
            int g = getGcd(a, b);
            ListNode* newNode = new ListNode(g);
            newNode->next = travel->next;
            travel->next = newNode;
            travel = newNode->next;
        }
        return head;
    }
};
