class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        this->n = k;
        if(nums.size() != 0)
        {
            sort(nums.begin(), nums.end());
            int i = nums.size()-1;
            while(k != 0 && i >= 0)
            {
                pq.push(nums[i]);
                --i;
                --k;
            }
        }
    }
    
    int add(int val) {
        if(pq.size() < n)
        {
            pq.push(val);
            return pq.top();
        }
        else {
            if(val <= pq.top())
                return pq.top();
            pq.push(val);
            pq.pop();
            return pq.top();
        }
    }
    
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
