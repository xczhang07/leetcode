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

Solution 2:

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
        else if(lists.size() == 1)
            return lists[0];
        int n = lists.size()-1;
        return merge(lists, 0, n);
    }
    
    ListNode* merge(vector<ListNode*>& lists, int left, int right)
    {
        if(left == right)
            return lists[left];
        int middle = left + (right-left)/2;
        ListNode* l1 = merge(lists, left, middle);
        ListNode* l2 = merge(lists, middle+1, right);
        return merge2Lists(l1, l2);
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        ListNode* newHead = new ListNode(0);
        ListNode* t = newHead;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                t->next = l1;
                l1 = l1->next;
            }
            else
            {
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
        }
        if(l1) t->next = l1;
        if(l2) t->next = l2;
        t = newHead->next;
        delete newHead;
        return t;
    } 
};
