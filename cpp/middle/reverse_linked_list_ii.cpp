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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head)
            return head;
        if(m > n)
            return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* pre = newHead;
        int step = 0;
        while(step != m-1)
        {
            ++step;
            pre = pre->next;
        }
        int reverse_times = n - m;
        ListNode* curr = pre->next;
        ListNode* post = curr->next;
        while(reverse_times > 0)
        {
            post = curr->next;
            curr->next = post->next;
            post->next = pre->next;
            pre->next = post;
            --reverse_times;
        }
        return newHead->next;
    }
    
    
};

/*
Conclusion: reverse linked list ii, a middle level algorithm issue. same idea with reverse linked list i

Time Complexity: O(n)
Space Complexity: O(1)
*/
