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
        int begin = 0;
        int end = lists.size()-1;
        return merge(lists, begin, end);
    }
    
    
    ListNode* merge(vector<ListNode*>& lists, int begin, int end)
    {
        if(begin > end)
            return NULL;
        else if(begin == end)
            return lists[begin];
        int m = begin + (end - begin)/2;
        ListNode* l1 = merge(lists, begin, m);
        ListNode* l2 = merge(lists, m+1, end);
        return merge2lists(l1, l2);
    }
    
    ListNode* merge2lists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        ListNode* dummy = new ListNode(0);
        ListNode* travel = dummy;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                travel->next = l1;
                l1 = l1->next;
            }
            else
            {
                travel->next = l2;
                l2 = l2->next;
            }
            travel = travel->next;
        }
        
        if(l1)
            travel->next = l1;
        if(l2)
            travel->next = l2;
        ListNode* newList = dummy->next;
        delete dummy;
        return newList;
    }
    
};
