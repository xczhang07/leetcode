/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        Node* travel = head;
        while(travel)
        {
            if(travel->child)
            {
                Node* post = travel->next;
                travel->next = travel->child;
                travel->child = NULL;
                travel->next->prev = travel;
                Node* tmp = travel->next;
                while(tmp->next)
                    tmp = tmp->next;
                tmp->next = post;
                if(post)
                    post->prev = tmp;
            }
            travel = travel->next;
        }
        return head;
    }
};


/*
Conclusion: an middle level leetcode algorithm issue, not diffcult, just need logic clear should be good enough.
Time Complexity: O(n*k)
Space Complexity: O(1)
*/
