class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        l.insert(l.begin(), x);
        m[x].push_back(l.begin());
        return;
    }
    
    int pop() {
        if(l.size() == 0) return -1;
        int top = *l.begin();
        m[top].pop_back();
        if(m[top].size() == 0)
            m.erase(top);
        l.erase(l.begin());
        return top;
    }
    
    int top() {
        if(l.size() == 0)
            return -1;
        return *l.begin();
    }
    
    int peekMax() {
        if(m.size() == 0)
            return -1;
        return m.rbegin()->first;
    }
    
    int popMax() {
        if(l.size() == 0)
            return -1;
        int max_val = m.rbegin()->first;
        auto iter = m[max_val].back();
        m[max_val].pop_back();
        if(m[max_val].size() == 0)
            m.erase(max_val);
        l.erase(iter);
        return max_val;
    }
    
private:
    list<int> l;
    map<int, vector<list<int>::iterator>> m;
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
