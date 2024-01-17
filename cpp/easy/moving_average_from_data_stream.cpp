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


class MovingAverage {
public:
    MovingAverage(int size) {
        this->_size = size;
        sum = 0;
    }
    
    double next(int val) {
        if(process_q.size() < this->_size) {
            sum += val;
            process_q.push(val);
            return (double)sum/(double)process_q.size();
        } else {
            sum -= process_q.front();
            sum += val;
            process_q.pop();
            process_q.push(val);
            return (double)sum/(double)process_q.size();
        }
    }

    int _size;
    int sum;
    queue<int> process_q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
