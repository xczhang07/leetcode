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
    bool isPalindrome(ListNode* head) {
        ListNode* node1 = head;
        ListNode* node2 = head;
        return helper(node1, node2);
    }
    
    bool helper(ListNode* node1, ListNode*& node2)
    {
        if(!node1)
            return true;
        bool flag = helper(node1->next, node2);
        int val1 = node1->val;
        int val2 = node2->val;
        node2 = node2->next;
        if(val1 == val2)
            return flag;
        else
            return false;
    }
};


Conclusion: an easy algoritm issue on leetcode, OA requires O(1) space, O(n) time complexity to solve it out, thus, recursive is 
the best solution for this issue. 


Time Complexity: O(n)
Space Complexity: O(1)
