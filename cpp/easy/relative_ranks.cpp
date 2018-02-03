class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int,int>> pq;
        vector<string> ret(nums.size(), "");
        int count = 1;
        
        for(int i = 0; i < nums.size(); ++i)
            pq.push(make_pair(nums[i], i));
        
        for(int i = 0; i < nums.size(); ++i, count++)
        {
            if(count == 1)
                ret[pq.top().second] = "Gold Medal";
            else if(count == 2)
                ret[pq.top().second] = "Silver Medal";
            else if(count == 3)
                ret[pq.top().second] = "Bronze Medal";
            else
                ret[pq.top().second] = to_string(count);
            pq.pop();
        }
        return ret;
    }
};


Conclusion:
an easy algorithm issue, solve this issue with the priority queue (store the element, the top value is always the largest value).
then iterate the given array, then we can get the result.


Time Complexity: O(n)
Space Complexity: O(n)
