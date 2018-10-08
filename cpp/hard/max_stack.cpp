class MaxStack {
public:
    /** initialize your data structure here. */
    
    struct ListNode
    {
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int v = 0): val(v), prev(NULL), next(NULL) {};
    };
    
    ListNode* head;
    ListNode* tail;
    map<int, vector<ListNode*>> m;
    
    MaxStack() {
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }
    
    void push(int x) {
        ListNode* newNode = new ListNode(x);
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
        m[x].push_back(newNode);
        return;
    }
    
    int pop() {
        ListNode* top = head->next;
        head->next = top->next;
        top->next->prev = head;
        int val = top->val;
        m[val].pop_back();
        if(m[val].empty())
            m.erase(val);
        return val;
    }
    
    int top() {
        ListNode* top = head->next;
        return top->val;
    }
    
    int peekMax() {
        return m.rbegin()->second.back()->val;
    }
    
    int popMax() {
        ListNode* maxNode = m.rbegin()->second.back();
        /* remove the node from doubly linked list */
        maxNode->prev->next = maxNode->next;
        maxNode->next->prev = maxNode->prev;
        /* remove the node from hash map */
        int maxVal = maxNode->val;
        m[maxVal].pop_back();
        if(m[maxVal].empty())
            m.erase(maxVal);
        return maxVal;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
 
 /*
 Conclusion:
 a hard level algorithm issue of leetcode.
 Time Complexity: peekMax is O(1), push and pop is O(logN)
 */
