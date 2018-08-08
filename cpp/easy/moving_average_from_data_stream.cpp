class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->window_size = size;
    }
    
    double next(int val) {
        double sum = 0;
        if(q.size() < this->window_size)
            q.push(val);
        else
        {
            q.pop();
            q.push(val);
        }
        int size = q.size();
        int q_size = size;
        while(size > 0)
        {
            int tmp_val = q.front();
            sum += tmp_val;
            q.pop();
            q.push(tmp_val);
            --size;
        }
        return double(sum/q_size);
    }
private:
    int window_size;
    queue<int> q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
 
 
 Conclusion:
 an easy ood+algorithm issue, no any other comments
