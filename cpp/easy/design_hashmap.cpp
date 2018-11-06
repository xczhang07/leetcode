class MyHashMap {
public:
    struct ListNode {
        int key, value;
        ListNode *next;
        ListNode(int key, int value) : key(key), value(value), next(nullptr) {}
    };
    ListNode **table;
    /** Initialize your data structure here. */
    MyHashMap() {
        table = new ListNode*[100];
        for (int i = 0; i < 100; i++) {
            table[i] = nullptr;
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashCode = key % 100;
        if (table[hashCode] == nullptr) {
            table[hashCode] = new ListNode(key, value);
            return;
        }
        
        ListNode *prev = nullptr, *curr = table[hashCode];
        while (curr != nullptr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = new ListNode(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashCode = key % 100;
        ListNode *curr = table[hashCode];
        while (curr != nullptr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashCode = key % 100;
        if (table[hashCode] == nullptr) {
            return;
        } else if (table[hashCode]->key == key) {
            table[hashCode] = table[hashCode]->next;
            return;
        }
        
        ListNode *prev = table[hashCode], *curr = prev->next;
        while (curr != nullptr) {
            if (curr->key == key) {
                prev->next = curr->next;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};
