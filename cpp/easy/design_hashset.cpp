struct Node {
    int val;
    Node* next;
    Node(int x): val(x), next(NULL) {}
};

class MyHashSet {
public:

    Node* head = NULL;

    MyHashSet() {
        head = new Node(-1);
    }
    
    void add(int key) {
        Node* newNode = new Node(key);
        Node* travel = head;
        while(travel->next) {
            if(travel->next->val == key) {
                return;
            }
            travel = travel->next;
        }
        travel->next = newNode;
        return;
    }
    
    void remove(int key) {
        Node* travel = head->next;
        Node* prev = head;
        while(travel) {
            if(travel->val == key) {
                prev->next = travel->next;
                break;
            }
            travel = travel->next;
            prev = prev->next;
        }
    }
    
    bool contains(int key) {
        Node* travel = head->next;
        while(travel) {
            if(travel->val == key) {
                return true;
            }
            travel = travel->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
