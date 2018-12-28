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


SolutionII without extra memory

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
       if(!head)
           return NULL;
        RandomListNode* l1 = head;
        /* 
            copy each node of the input linked-list, and insert
            the new node after each node.
        */
        while(l1 != NULL)
        {
            RandomListNode* newNode = new RandomListNode(l1->label);
            newNode->next = l1->next;
            l1->next = newNode;
            l1 = l1->next->next;
        }
        
        /* copy the random pointer */
        RandomListNode* newList = head->next;
        l1 = head;
        while(l1 != NULL)
        {
            if(l1->random)
                l1->next->random = l1->random->next;
            l1 = l1->next->next;
        }
        
        /* segregate the new list from the combine list */
        l1 = head;
        RandomListNode* l2 = l1->next;
        while(l1 != NULL)
        {
            l2 = l1->next;
            l1->next = l2->next;
            if(l2->next)
                l2->next = l1->next->next;
            l1 = l1->next;
        }
        return newList;
    }
};
