class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size())
            return -1;
        priority_queue<int> pq; // priority queue, if we push 8, 9, 5, 4, 10, the sequence of num should be: 10, 9 ,8, 5, 4
        for(auto num : nums)
            pq.push(num);
        while(k > 1)
        {
            k--;
            pq.pop();
        }
        return pq.top();
    }
};


Conclusion:
we can use priority queue to resolve this issue.

Time Complexity: O(n+klogn), every time, the pop operation of priority_queue is logn, and we need to perform this operation k times.
Space Complexity: O(n)
