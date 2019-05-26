Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 


class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_q.push(num);
        max_q.push(min_q.top());
        min_q.pop();
        if(min_q.size() < max_q.size())
        {
            min_q.push(max_q.top());
            max_q.pop();
        }
        return;
    }
    
    double findMedian() {
        if(min_q.size() > max_q.size())
            return min_q.top();
        else
            return double((min_q.top()+max_q.top())/2.0);
    }
    
private:
    priority_queue<int, vector<int>, greater<int>> max_q;
    priority_queue<int, vector<int>, less<int>> min_q;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
