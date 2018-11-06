class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq; /* 1, store the index of element in nums.
                          2, maintain the deque in the decreasing order */
        for(int i = 0; i < nums.size(); ++i)
        {
            if(!dq.empty() && (i-dq.front() == k))
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k-1) /* start to push the element into vector from index k-1 */
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

/*
a hard level algorithm issue, we are using deque data structure to resolve this issue.
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
