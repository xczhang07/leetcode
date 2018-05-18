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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur1=headA,*cur2=headB;
        while(cur1!=cur2)
        {
            if(cur1==NULL)
                cur1=headA;
            else 
                cur1=cur1->next;          
            if(cur2==NULL)
                cur2=headB;
            else 
                cur2=cur2->next;
        
        }   
         return cur1;   
    }
    
    
};


Conclusion: an easy level algorithm issue, we just can treat as circular linked list to solve this issue.

Time Complexity: O(n)
Space Complexity: O(1)
