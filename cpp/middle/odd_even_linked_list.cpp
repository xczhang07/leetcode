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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* oddHead = new ListNode(0);
        ListNode* evenHead = new ListNode(0);
        int num = 1;
        ListNode* travel = head;
        ListNode* oddTravel = oddHead;
        ListNode* evenTravel = evenHead;
        while(travel)
        {
            if(num%2 == 1)
            {
                oddTravel->next = travel;
                travel = travel->next;
                oddTravel = oddTravel->next;
                oddTravel->next = NULL;
            }
            else
            {
                evenTravel->next = travel;
                travel = travel->next;
                evenTravel = evenTravel->next;
                evenTravel->next = NULL;
            }
            
            ++num;
        }
        oddTravel->next = evenHead->next;
        return oddHead->next;
    }
};

Conclusion:
a middle level algorithm issue, not diffcult, straight forward.
Time Complexity: O(N)
Space Complexity: O(1)
