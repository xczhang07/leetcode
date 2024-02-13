/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    //Find the intersection of two linked list
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* t1 = p;
        Node* t2 = q;
        while(t1->val != t2->val) {
            t1 = (t1->parent == NULL)?q:t1->parent;
            t2 = (t2->parent == NULL)?p:t2->parent;
        }
        return t1;
    }
};
