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
    int getListLen(ListNode* head)
    {
        if(!head)
            return 0;
        int len = 1;
        ListNode* tmp = head;
        while(tmp->next)
        {
            ++len;
            tmp = tmp->next;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getListLen(head);
        if(len < k)
            return head;
        int group_number = len / k;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* prev = newHead;
        ListNode* curr = head;
        int reverse_times = 0;
        while(reverse_times < group_number)
        {
            int i = 0;
            while(i!=k-1)
            {
                ListNode* post = curr->next;
                curr->next = post->next;
                post->next = prev->next;
                prev->next = post;
                ++i;
            }
            prev = curr;
            curr = prev->next;
            ++reverse_times;
        }
        return newHead->next;
    }
};

Conclusion: a hard level leetcode issue, time complexity is O(n). space complexity is: O(1)
