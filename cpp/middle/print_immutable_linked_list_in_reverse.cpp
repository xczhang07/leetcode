/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void recursivePrintList(ImmutableListNode* node) {
        if(node == NULL) {
            return;
        }
        recursivePrintList(node->getNext());
        node->printValue();
    }

    void printLinkedListInReverse(ImmutableListNode* head) {
        recursivePrintList(head);
    }
};
