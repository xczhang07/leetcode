class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(ret.empty())
        {
            ret.push_back(x);
            minSt.push_back(x);
        }
        else
        {
            ret.push_back(x);
            if(x <= minSt.back())
                minSt.push_back(x);
        }
    }
    
    void pop() {
        if(ret.empty())
            return;
        int top_val = ret.back();
        if(top_val == minSt.back())
            minSt.pop_back();
        ret.pop_back();
    }
    
    int top() {
        if(ret.empty())
            return -1;
        int top_val = ret.back();
        return top_val;
    }
    
    int getMin() {
        
        return minSt.back();
    }

private:
    vector<int> ret;
    vector<int> minSt;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


Conclusion: an easy algorithm issue; actually, it tests the data structure of stack, we can use two vectors to implement in c++

Time Complexity: O(n)
Space Complexity:O(n)
