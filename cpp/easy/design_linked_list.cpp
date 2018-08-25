class MyLinkedList {
private:
    vector<int> array;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= array.size()) {
            return -1;
        }
        return array[index];
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        array.insert(array.begin(), val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        array.push_back(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > array.size()) {
            return;
        }
        if (index == array.size()) {
            array.push_back(val);
            return;
        }
        array.insert(array.begin() + index, val);
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= array.size()) {
            return;
        }
        array.erase(array.begin() + index);
    }
};


/*
Conclusion:
No comments, an easy level algorithm issue, using c++ vector can fully implement it

*/
