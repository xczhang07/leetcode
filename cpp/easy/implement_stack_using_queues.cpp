class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        innerQ.push(x);
        int size = innerQ.size();
        while(size != 1)
        {
            innerQ.push(innerQ.front());
            innerQ.pop();
            --size;
        }
        return;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = innerQ.front();
        innerQ.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return innerQ.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return innerQ.empty();
    }
    
    private:
        queue<int> innerQ;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */


Conclusion: an easy level algorithm issue, the key point at here is the push function implementation.
