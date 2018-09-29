/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        if(!head)
        {
            newNode->next = newNode;
            return newNode;
        }
        Node* travel = head;
        Node* min_node = head;
        bool insert = false;
        while(travel) {
            if(travel->val < min_node->val)
                min_node = travel;
            Node* post = travel->next;
            if(travel->val <= insertVal && post->val >= insertVal) {
                newNode->next = post;
                travel->next = newNode;
                insert = true;
                break;
            }
            else
                travel = travel->next;
            if(travel == head)
                break;
        }
        if(!insert) {
            travel = head;
            while(travel->next != min_node)
                travel = travel->next;
            travel->next = newNode;
            newNode->next = min_node;
        }
        return head;
    }
};

