class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(st2.empty())
        {
            if(!st1.empty())
            {
                while(!st1.empty())
                {
                    int val = st1.top();
                    st2.push(val);
                    st1.pop();
                }
            }
            else
                return -1;
        }
        int top = st2.top();
        st2.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if(st2.empty())
        {
            if(!st1.empty())
            {
                while(!st1.empty())
                {
                    int val = st1.top();
                    st2.push(val);
                    st1.pop();
                }
            }
            else
                return -1;
        }
        return st2.top();
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
       return st1.empty() && st2.empty(); 
    }
private:
    stack<int> st1;
    stack<int> st2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

Conclusion: 
an easy algorithm issue on leetcode, using a queue with stacks (using two stacks is good enough for queue implementation)

