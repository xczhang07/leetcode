/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* m = head;
        RandomListNode* n = head;
        unordered_map<RandomListNode*, RandomListNode*> mp;
        while(m)
        {
            mp[m] = new RandomListNode(m->label);
            m = m->next;
        }
        while(n)
        {
            mp[n]->next = mp[n->next];
            mp[n]->random = mp[n->random];
            n = n->next;
        }
        return mp[head];
    }
};

/*
Conclusion:
a middle level algorithm issue.
Time Complexity: O(n)
Space Complexity: O(n)
*/
