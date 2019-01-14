class MyCircularQueue {

private:
    int head;
    int tail;
    int cnt;
    vector<int> q;
    
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q.resize(k);
        head = 0;
        tail = 0;
        cnt = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
       if(isFull())
           return false;
        q[tail] = value;
        tail = (tail+1) % q.size();
        ++cnt;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;
        q[head] = 0;
        head = (head+1) % q.size();
        --cnt;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
            return -1;
        return q[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
       if(isEmpty())
           return -1;
        if(tail == 0)
            return q[q.size()-1];
        return q[tail-1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return cnt == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return cnt == q.size();
    }
};
