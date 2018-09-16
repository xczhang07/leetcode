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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> container;
        for(int i = 0; i < G.size(); ++i)
            container.insert(G[i]);
        int circle = 0;
        ListNode* travel = head;
        bool flag = false;
        while(travel)
        {
            int val = travel->val;
            if(container.find(val) != container.end())
            {
                if(!flag)
                {
                    ++circle;
                    flag = true;
                }
            }
            else
                flag = false;
            travel = travel->next;
        }
        return circle;
    }
};


/*
Conclusion:
an middle level algorithm issue, we can use hash-set and travel the linked list to resolve this issue.
Time Complexity: O(n)
Space Complexity: O(n)
*/
