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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if(lists.size() == 0)
           return NULL;
        int end = lists.size()-1;
        while(end)
        {
            int begin = 0;
            while(begin < end)
            {
                lists[begin] = merge2lists(lists[begin], lists[end]);
                ++begin;
                --end;
            }
        }
        return lists[0];
    }
    
    ListNode* merge2lists(ListNode* head1, ListNode* head2)
    {
        ListNode* newHead = new ListNode(0);
        ListNode* travel = newHead;
        while(head1&&head2)
        {
            if(head1->val < head2->val)
            {
                travel->next = head1;
                head1 = head1->next;
            }
            else
            {
                travel->next = head2;
                head2 = head2->next;
            }
             travel = travel->next;
        }
        if(head1)
            travel->next = head1;
        if(head2)
            travel->next = head2;
        return newHead->next;
    }
};


/*
a hard level algorithm issue on leetcode, we use a kind of binary search to resolve this issue.
Space Complexity: O(1)
Time Complexity: O(nklogk)
reference link: http://bangbingsyb.blogspot.com/2014/11/leetcode-merge-k-sorted-lists.html
*/
