Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /* 
        time complexity is o(nlogk)
        space complexity is: o(n)
           */
        if(nums.size() == 0)
            return {};
        vector<int> ret;
        unordered_map<int,int> m; /* this map is used to store every element frequency */
        for(int num : nums)
            m[num]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto e : m)
        {
            if(pq.size() < k)
                pq.push(make_pair(e.second, e.first));
            else if(pq.top().first < e.second)
            {
                pq.pop();
                pq.push(make_pair(e.second, e.first));
            }
        }
        
        while(!pq.empty())
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};
